from bs4 import BeautifulSoup
import  requests


headers = {
    'User-Agent':'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3325.181 Safari/537.36',
    'Referer':'https://www.douban.com/',
}
def login():
    response = requests.get('http://zyfw.prsc.bnu.edu.cn/taglib/CombBoxServlet.jsp', headers=headers)
    result = response.json()
    print(result)
 '''   captchaURL = result['Request URL']
    captchaPolicy = result['Policy']
    # print (captchaURL,captchaPolicy)
    response = requests.get(captchaURL, header=headers)
    codeImg = response.content.decode()
    fn = open('code.png', 'wb')
    fn.write(codeImg)
    fn.close()

    data = {
        'source': 'index_nav',
        'form_email': '18810719923',
        'form_password': 'grandline7',
        'captcha-solution': input(),
        'captcha-id': captchaPolicy,
    }
    response = requests.post('https://www.douban.com/accounts/login', data=data, header=header)
'''