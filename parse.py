import time
import csv
import os
import requests
import telebot
import codecs
from bs4 import BeautifulSoup
from selenium import webdriver
from webdriver_manager.firefox import GeckoDriverManager
from webdriver_manager.chrome import ChromeDriverManager
from selenium.common.exceptions import NoSuchElementException


  
FILE = 'facebook.csv'
bot = telebot.TeleBot("1017543590:AAEluQgSWsJ7viadUhOrAD2XkxRXGAYZ4Bo")

LOGIN_URL = 'https://www.facebook.com/login.php'



class FacebookLogin():
    def __init__(self, email, password, browser='Chrome'):
        
        self.email = email
        self.password = password
        if browser == 'Chrome':           
            self.driver = webdriver.Chrome(executable_path=ChromeDriverManager().install())
        elif browser == 'Firefox':
            self.driver = webdriver.Firefox(executable_path=GeckoDriverManager().install())
            #self.driver = webdriver.Chrome()
        self.driver.get(LOGIN_URL)
        time.sleep(1) 
 
 
 
    def login(self):
        email_element = self.driver.find_element_by_id('email')#m_login_email
        email_element.send_keys(self.email) 
 
        password_element = self.driver.find_element_by_id('pass')#u_0_1
        password_element.send_keys(self.password)
 
        login_button = self.driver.find_element_by_id('loginbutton')#signup-button
        login_button.click() 
 
        time.sleep(1)
    


    def save_file(self, friends,path):
        self.driver.quit()
        with open(path, 'w', newline='',encoding="utf8") as file:
            writer = csv.writer(file, delimiter=';')
            writer.writerow([u'Друзья', u'Link',u'Образование',u'Места проживания',u'Контактная информация',u'Основная информация',u'Семейное положение',])
            for item in friends:
                writer.writerow([ item['Друзья'], item['link'],item['Образование'],item['Места проживания'], item['Контактная информация'],item['Основная информация'], item['Семейное положение']])

    def save_post(self, postttt,path):
        self.driver.quit()
        with open(path, 'w', newline='',encoding="utf8") as file:
            writer = csv.writer(file, delimiter=';')
            writer.writerow([])
            writer.writerow([])
            writer.writerow(['postlarning sanasi', 'postlarning link'])
            for item in postttt:
                writer.writerow([ item['post data'],item['link']])
             



    def get_about(self,friends,url):
        hh=url.replace('www', 'm')
        self.driver.get(hh+'/about')
        time.sleep(2)
        initial = self.driver.page_source
        soup=BeautifulSoup(initial,"html.parser")
        
        
        obr=soup.findAll('a',{'class':'cn'})
        gorod=soup.findAll('div',{'class':'eh'})
        mobile=soup.findAll('span',{'dir':'ltr'})
        god=soup.findAll('div',{'class':'eh'})
        sem=soup.findAll('div',{'class':'dq el dr'})
        
        
        j=0
        for item in friends:
            if j<=len(obr)-1:
                item['Образование']=obr[j].text if len(obr)>0 else " "
            else:
                item['Образование']=" "
            j=j+1
        
        j=0
        for item in friends:
            if j<=len(gorod)-1:
                item['Места проживания']=gorod[j].text if len(gorod)>0 else " "
            else:
                item['Места проживания']=" "
            j=j+1
        
        j=0
        for item in friends:
            if j<=len(mobile)-1:
                item['Контактная информация']=mobile[j].text if len(mobile)>0 else " "
            else:
                item['Контактная информация']=" "
            j=j+1
        
        j=0
        for item in friends:
            if j<=len(god)-1:
                item['Основная информация']=god[j].text if len(god)>0 else " "
            else:
                item['Основная информация']=" "
            j=j+1
        
        j=0
        for item in friends:
            if j<=len(sem)-1:
                item['Семейное положение']=sem[j].text if len(god)>0 else " "
            else:
                item['Семейное положение']=" "
            j=j+1
        return friends
        


    def get_post(self,friends,url):
        
        hh=url.replace('www', 'm')

        p=[]
        
        self.driver.get(hh)
        time.sleep(2)

        initial = self.driver.page_source
        soup=BeautifulSoup(initial,"html.parser")

        next_page=soup.findAll('div',{'class':'acw apm'})
        j=True
        for nextd in next_page:
            if nextd==next_page[len(next_page)-1]:
                break
            if j:
                j=False
                continue
            #print(nextd.find('a').get('href'))
            self.driver.get('https://m.facebook.com'+nextd.find('a').get('href'))
            time.sleep(2)

            initial = self.driver.page_source
            soup=BeautifulSoup(initial,"html.parser")
            postes=soup.findAll('article',{'class':'bo bp bq'})
            
            for s in postes:
                link=s.findAll('a')
                
                p.append({
                    'link':'https://m.facebook.com'+link[2].get('href') ,
                    'post data':s.findAll('abbr')[0].text if len(s.findAll('abbr')) != 0 else " "
                })
            
               
            return p








    def get(self,url):
        if url.find("friends")==-1:
            sss=url+"/friends"
        self.driver.get(sss) 
        time.sleep(2)
        friends=[]
        initial = self.driver.page_source
        soup=BeautifulSoup(initial,"html.parser")
        count=soup.findAll('span',{'class':'oi732d6d ik7dh3pa d2edcug0 qv66sw1b c1et5uql e9vueds3 j5wam9gi knj5qynh q66pz984'})
        k= len(friends)                           
        while int(count.text) if len(count) > 0 else k >=len(friends):
            initial = self.driver.page_source
            soup=BeautifulSoup(initial,"html.parser")
            time.sleep(1)
            self.driver.execute_script("window.scrollTo(0,document.body.scrollHeight)")
            
            items=soup.findAll('a',{'class':'oajrlxb2 g5ia77u1 qu0x051f esr5mh6w e9989ue4 r7d6kgcz rq0escxv nhd2j8a9 nc684nl6 p7hjln8o kvgmc6g5 cxmmr5t8 oygrvhab hcukyx3x jb3vyjys rz4wbd8a qt6c0cv9 a8nywdso i1ao9s8h esuyzwwr f1sip0of lzcic4wl gmql0nx0 gpro0wi8'})                      
            for item in items:
                friends.append(item.text)

        initial = self.driver.page_source
        soup=BeautifulSoup(initial,"html.parser")
        friends=[]

        items=soup.findAll('a',{'class':'oajrlxb2 g5ia77u1 qu0x051f esr5mh6w e9989ue4 r7d6kgcz rq0escxv nhd2j8a9 nc684nl6 p7hjln8o kvgmc6g5 cxmmr5t8 oygrvhab hcukyx3x jb3vyjys rz4wbd8a qt6c0cv9 a8nywdso i1ao9s8h esuyzwwr f1sip0of lzcic4wl gmql0nx0 gpro0wi8'})                      
        
        for item in items:
            friends.append({
                'Друзья':item.text,
                'link':item.get('href'),
            })

        return friends
        
        
        


       
      

def run(link,message):
    fb_login = FacebookLogin(email='+', password='', browser='Firefox')
    fb_login.login()

    fr=fb_login.get(link)

    postt=fb_login.get_post(fr,link)

    fr=fb_login.get_about(fr,link)

    fb_login.save_file(fr,FILE)
    fb_login.save_post(postt,FILE)
    f=open(FILE)
    bot.send_document(message.chat.id,f)

@bot.message_handler(commands=['start'])
def send_welcome(message):
    bot.send_message(message.chat.id,"Link!!!")

@bot.message_handler(content_types=['text'])
def main(message): 
    if message.text.find("facebook") != -1:
        sss=message.text
        bot.send_message(message.chat.id,"Wait please!")
        run(sss,message)
        
    else:
        bot.send_message(message.chat.id,"Sory only Facebook account link!!!")

bot.polling()

