from bs4 import BeautifulSoup
import urllib2,os

web = "https://www.starbucks.com/promo/proteinbox"
responese = urllib2.urlopen(web)
html = responese.read()

#print html
#BeautifulSoup(parsing,parser)
soup = BeautifulSoup(html,"html.parser") #nampung hasil yg udah di parse

ol = soup.find("ol",{"class":"blocks blocks-three-up section_blocks"}) #buat dapetin semua tag ol,{buat spesifikin tag yg mau diambil}

#print ol
foods = ol.findChildren("li") #dapetin semua tag li yg ada di bawahnya ol

class Food:
    def __init__(self,name,pic,desc):
        self.name = name
        self.pic = pic
        self.desc = desc

food_list = []

for food in foods:
    name = food.findChild("span").text
    pic = food.findChild("img")["src"]
    desc = food.findChild("p").text

    food_list.append(Food(name,pic,desc))

for f in food_list:
    text = "Name: {} \n Pic: {}\n Desc: {}\n {}".format(f.name,f.pic,f.desc,"------------------------------------")

    print text

filename = os.path.dirname(__file__)+"\\datamakanan.txt"
for f in food_list:
    text = "Name: {} \n Pic: {}\n Desc: {}\n {}\n".format(f.name,f.pic,f.desc,"----------------------------------")
    open(filename,"a").write(text)
