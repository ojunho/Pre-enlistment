class father():
    def handsome(self):
        print("handsome")

class broether(father):
    '''son'''

class sister(father):
    def pretty(self):
        print("Pretty")

    def handsome(self):
        print("잘생김.")

brother = broether()
brother.handsome()

girl = sister()
girl.handsome()

brother.handsome()