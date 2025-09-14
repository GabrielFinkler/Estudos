from tkinter import *

# posição do jogador
global x_jogador
global y_jogador
global tam_jogador
global fim_jogo
x_jogador = 10
y_jogador = 165
fim_jogo = 0

tam_jogador = 20
 
# ações ao pressionar as respectivas teclas
def left(ev):
    global x_jogador
    x_jogador -= 3
    
def right(ev):
    global x_jogador
    x_jogador += 3

def up(ev):
    global y_jogador
    y_jogador -= 3

def down(ev):
    global y_jogador
    y_jogador += 3

# janela principal 
root = Tk()

# área de desenho 
C = Canvas(root, bg="white",
           height=600, width=800)

# atualização da tela
def loop():

    # limpa a tela
    C.delete("all")
    
    global x_jogador
    global y_jogador
    global fim_jogo
    global tam_jogador

    # desenha o jogador 
    C.create_rectangle(x_jogador, y_jogador,
                       x_jogador + tam_jogador, y_jogador + tam_jogador, 
                    outline = "black", fill = "green", 
                    width = 1)

    # PREDES DO LABIRINTO



    # >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    # seu trabalho deve ser desenvolvido aqui


    # perde o jogo se:
    #    1) o jogador sair da janela
    #    2) ao colidir com paredes

    # crie um jogo legal :)
    # com no mínimo:
    #    a) 20 paredes
    #    b) 03 passagens secretas
    

    
    # parede 1
    C.create_line(300, 50,300, 150, width=1)
    if y_jogador + tam_jogador<= 160 and x_jogador + tam_jogador <=263:
        fim_jogo = 1
    #parede do inicio
    C.create_line(0, 150,0, 200, width=1)
    if x_jogador + tam_jogador<=20:
        fim_jogo = 1
    #parede 2
    C.create_line(250, 50,250, 150, width=1)
    if y_jogador + tam_jogador<= 160 and x_jogador + tam_jogador <=263:
        fim_jogo = 1
    #parede 3
    C.create_line(250, 150,0, 150, width=1)
    if y_jogador + tam_jogador <= 163 and x_jogador + tam_jogador <=253:
            fim_jogo = 1
    #parede 4
    C.create_line(300, 200,0, 200, width=1)
    if y_jogador + tam_jogador >=208 and x_jogador + tam_jogador <=310:
        fim_jogo = 1
    #parede 5
    C.create_line(250, 50,300, 50, width=1)
   
    #parede 6
    C.create_line(300, 150,350, 150, width=1)
    if y_jogador + tam_jogador <= 163 and x_jogador + tam_jogador >= 307  :
        fim_jogo = 1
    #parede 7
    C.create_line(350, 150,350, 350, width=1)
    if y_jogador + tam_jogador >=163 and x_jogador + tam_jogador >= 358 and y_jogador + tam_jogador <=363 and x_jogador + tam_jogador <= 400:
        fim_jogo = 1
    #parede 8
    C.create_line(300, 200,300, 400, width=1)
    
    #parede 9
    C.create_line(300, 400,500, 400, width=1)
    if y_jogador + tam_jogador >= 405:
        fim_jogo = 1
    #parede 10
    C.create_line(350, 350,400, 350, width=1)
    
    #parede 10/2
    C.create_line(400, 350,400, 300, width=1)
    if y_jogador + tam_jogador <= 360 and x_jogador + tam_jogador >= 358 and x_jogador + tam_jogador <=400:
        fim_jogo = 1
    #parede 11
    C.create_line(400, 300,450, 300, width=1)
    if y_jogador + tam_jogador <= 310 and x_jogador + tam_jogador >= 400 and x_jogador + tam_jogador <=450 :
        fim_jogo = 1
    #parede 12
    C.create_line(450, 300,450, 350, width=1)
    if y_jogador + tam_jogador <= 350 and x_jogador + tam_jogador >= 455:
        fim_jogo = 1
    #parede 13
    C.create_line(450, 350,500, 350, width=1)
    if y_jogador + tam_jogador <= 360 and x_jogador + tam_jogador >= 455:
        fim_jogo = 1


    #Vitória
    C.create_rectangle(550, 350,
                       500, 400, 
                    outline = "green", fill = "green", 
                    width = 1)         

    
     #passagem 1
    C.create_rectangle(250, 60,
                       300, 110, 
                    outline = "blue", fill = "blue", 
                    width = 1)
    if x_jogador + tam_jogador/2 > 250 and x_jogador + tam_jogador/2 < 300 \
              and y_jogador + tam_jogador/2 > 60 and y_jogador + tam_jogador/2 < 110:
         x_jogador = 415
         y_jogador = 310
        
 

    # >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        

    # fim do jogo(perder)
    if fim_jogo == 1:
        C.create_rectangle(200, 200,
                       600, 400, 
                    outline = "black", fill = "red",
                    width = 1)
        C.create_text(400, 300, text="Você morreu", fill="black", font=('Helvetica 15 bold'))   
    

    #fim do jogo(ganhar)
    if x_jogador + tam_jogador >= 507:
        C.create_rectangle(200, 200,
                       600, 400, 
                    outline = "black", fill = "green",
                    width = 1)
        C.create_text(400, 300, text="Você ganhou", fill="black", font=('Helvetica 15 bold'))   

    root.after(10, loop)

# eventos do teclado
root.bind('<Left>', left)
root.bind('<Right>', right)
root.bind('<Up>', up)
root.bind('<Down>', down)

root.after(10, loop)
 
C.pack()
mainloop()
