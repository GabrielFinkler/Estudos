from turtle import Turtle, tracer, update
import sys


def desenho(t, dist, nivel):
     if nivel == 0:
        t.forward(dist)
     else:
        nivel -= 1
        dist = dist / 3
        desenho(t, dist, nivel)
        t.left(60)
        desenho(t, dist, nivel)
        t.right(120)
        desenho(t, dist, nivel)
        t.left(60)
        desenho(t, dist, nivel)


def koch():

    t = Turtle()
    t.speed(0)
    t.pencolor("black")
    desenho(t, 200, 5)
    t.right(120)
    desenho(t, 200, 5)
    t.right(120)
    desenho(t, 200, 5)
    t.right(120)

koch()
