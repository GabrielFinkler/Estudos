from tkinter import *
from tkinter.ttk import*
import random


# posição do jogador
global x_jogador
global y_jogador
global tam_jogador
global fim_jogo
x_jogador = 325
y_jogador = 500
fim_jogo = 0
tam_jogador = 80
global pts
pts = 0
global t1
t1=25
global t2
t2=25
global t3
t3=25
global t4
t4=25
global t5
t5=25
global t6
t6=25
global t7
t7=20
global t8
t8=20
global a
global b
a=242
b=20
global c
global d
c=200
d=240
global e
global f
e=150
f=500
global g
global h
g=410
h=20
global i
global j
i=450
j=240
global k
global l
k=507
l=500
global o
global p
o=0
p=20
global q
global r
q=0
r=20
global x
x=295
global z
z=320
global ç
ç=0
# ações ao pressionar as respectivas teclas
def left(ev):
    global x_jogador
    x_jogador -= 3
    
def right(ev):
    global x_jogador
    x_jogador += 3

#def up(ev):
   # global y_jogador
    #y_jogador -= 3

#def down(ev):
    #global y_jogador
    # y_jogador += 3

# janela principal 
root = Tk()

# área de desenho 
C= Canvas(root, bg="white",
           height=600, width=800)

# atualização da tela
def loop():

    # limpa a tela
    C.delete("all")
    
    global x_jogador
    global y_jogador
    global fim_jogo
    global tam_jogador
    global t1
    global t2
    global t3
    global t4
    global t5
    global t6
    global t7
    global t8
    global x
    global z
    global ç
    global pts
    

    # desenha o jogador 
    C.create_rectangle(x_jogador, y_jogador,
                       x_jogador + tam_jogador, y_jogador + tam_jogador, 
                    outline = "black", fill = "red", 
                    width = 1)

    



#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
# Arbustos

    t1+=0.1
    t2+=0.1
    t3+=0.1
    t4+=0.1
    t5+=0.1
    t6+=0.1
    t7+=0.18
    t8+=0.18
    #arbusto 1

    global a
    global b
    if b > 600:
        a=242
        b=-10
        t1=25
    a-=0.6
    b+=2
    
    C.create_oval(a, b,a+t1, b+t1, fill = "green")

    #arbusto 2

    global c
    global d
    if d > 600:
        c=242
        d=-10
        t2=25
    c-=0.6
    d+=2
    
    C.create_oval(c, d,c+t2, d+t2, fill = "green")

    #arbusto 3

    global e
    global f
    if f > 1220:
        e=242
        f=-10
        t3=25
    e-=0.6
    f+=2
    
    C.create_oval(e, f,e+t3, f+t3, fill = "green")

    #arbusto 4

    global g
    global h
    if h > 600:
        g=410
        h=-10
        t4=25
    g+=0.4
    h+=2
    
    C.create_oval(g, h,g+t4, h+t4, fill = "green")
    
    #arbusto 5

    global i
    global j
    if j > 600:
        i=410
        j=-10
        t5=25
    i+=0.4
    j+=2
    
    C.create_oval(i, j,i+t5, j+t5, fill = "green")
    
    #arbusto 6

    global k
    global l
    if l > 1220:
        k=410
        l=-10
        t6=25
    k+=0.4
    l+=2
    
    C.create_oval(k, l,k+t6, l+t6, fill = "green")
#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 #Buracos e pontos
    
    #perder

    global o
    global p
    global x
    if p > 600:
        x=random.randint(290,320)
        y=random.randint(-260,10)
        p=y
        t7=20
        ç=1

    o=x
    o-=0.1
    p+=2
    xc=o+40
    yc=p+10
    #print("" + str(o) + " " + str(p) + "     " + str(x_jogador) + "  500")

    if pts<300 :
        if yc>500 and xc>x_jogador and xc<x_jogador+80 and yc<580:
            #print("-----------------------------------")
            fim_jogo = 1
    C.create_oval(o, p,o+t7, p+t7, fill = "black")
    
    
    if ç==1:
        
        #ganhar
        global q
        global r
        global z
        if r > 600:
            z=random.randint(290,380)
            r=-10
            t8=20
        q=z
        q-=0.1
        r+=2
        xxc=q+10
        yyc=r+10
        if pts<300 and fim_jogo == 0:
            if yyc>500 and xxc>x_jogador and xxc<x_jogador+80 and yyc<580:
                pts+=1
            #print("-----------------------------------")
        
        C.create_oval(q, r,q+t8, r+t8, fill = "yellow")
        
    else:
        pass
#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#paredes
    # parede 1
    C.create_line(300, 0, 150, 800, width=1)
    if x_jogador + tam_jogador/2 < 247:
        fim_jogo = 1
    # parede 2
    C.create_line(400, 0, 550, 800, width=1)
    if x_jogador + tam_jogador/2 > 453:
        fim_jogo = 1  
#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#finais de jogo        

    # fim do jogo
    if fim_jogo == 1:

        C.create_rectangle(200, 200,
                       600, 400, 
                    outline = "black", fill = "red", 
                    width = 1)
        C.create_text(400, 230, text="Você Perdeu", fill="black", font=('Helvetica 15 bold'))
        C.create_text(395, 310, text=("Pontuação:",pts), fill="black", font=('Helvetica 15 bold'))

    #fim do jogo(ganhar)
    if pts>=300:
        C.create_rectangle(200, 200,
                       600, 400, 
                    outline = "black", fill = "green",
                    width = 1)
        C.create_text(400, 230, text="Você ganhou", fill="black", font=('Helvetica 15 bold'))
        C.create_text(395, 310, text=("Pontuação:",pts), fill="black", font=('Helvetica 15 bold'))
#>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#extras
    root.after(10, loop)
     
# eventos do teclado
root.bind('<Left>', left)
root.bind('<Right>', right)
#root.bind('<Up>', up)
#root.bind('<Down>', down)

root.after(10, loop)

C.pack() 
mainloop()

