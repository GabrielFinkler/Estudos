class Retangulo:
    def __init__(self,b,h):
        if b != None:
            self.base = b
        else:
            self.base = 0
        if h != None:
            self.altura = h
        else:
            self.altura = 0
    def Desenha(self):
        with open("retangulo.txt","w") as f:
            f.write("*" * self.base + "\n")
            for i in range(self.altura - 2):
                f.write("*" + " " * (self.base-2) + "*" + "\n")
            f.write("*" * self.base + "\n")
    def Carrega(self):
        with open("retangulo.txt","r") as g:
            a = g.readlines()
            cont = 0
            b = 0
            for i in range(len(a)):
                cont+=1
                if b == 0:
                    self.base = range(i)
                    b+=1
            b = 0       
            self.altura = cont
            print(self.altura)
            print(self.base)
            
ret1 = Retangulo(26,15)
ret1.Desenha()

#ret2 = Retangulo(0,0)
#ret2.Carrega()
