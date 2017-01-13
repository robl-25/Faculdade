from visual import *
import pykinect
from pykinect import nui
from pykinect.nui import JointId
from math import sqrt

class Skeleton:
    def __init__(self, f):
        self.frame = f
        self.joints = [sphere(frame=f, radius=0.08, color=color.yellow)
                       for i in range(20)]
        self.joints[3].radius = 0.125
        self.bones = [cylinder(frame=f, radius=0.05, color=color.yellow)
                      for bone in _bone_ids]
        self.rightHand = self.joints[11]
        self.leftHand = self.joints[7]
        self.rightFoot = self.joints[19]
        self.leftFoot = self.joints[15]

    def update(self):
        updated = False
        for skeleton in _kinect.skeleton_engine.get_next_frame().SkeletonData:
            if skeleton.eTrackingState == nui.SkeletonTrackingState.TRACKED:

                
                for joint, p in zip(self.joints, skeleton.SkeletonPositions):
                    joint.pos = (p.x, p.y, p.z)

                
                for bone, bone_id in zip(self.bones, _bone_ids):
                    p1, p2 = [self.joints[id].pos for id in bone_id]
                    bone.pos = p1
                    bone.axis = p2 - p1
                updated = True
        return updated

def draw_sensor(f):
    
    box(frame=f, pos=(0, 0, 0), length=0.2794, height=0.0381, width=0.0635,
        color=color.blue)
    cylinder(frame=f, pos=(0, -0.05715, 0), axis=(0, 0.0127, 0), radius=0.0381,
             color=color.blue)
    cone(frame=f, pos=(0, -0.04445, 0), axis=(0, 0.01905, 0), radius=0.0381,
         color=color.blue)
    cylinder(frame=f, pos=(0, -0.05715, 0), axis=(0, 0.0381, 0), radius=0.0127,
             color=color.blue)
    cylinder(frame=f, pos=(-0.0635, 0, 0.03175), axis=(0, 0, 0.003),
             radius=0.00635, color=color.red)
    cylinder(frame=f, pos=(-0.0127, 0, 0.03175), axis=(0, 0, 0.003),
             radius=0.00635, color=color.red)
    cylinder(frame=f, pos=(0.0127, 0, 0.03175), axis=(0, 0, 0.003),
             radius=0.00635, color=color.red)
    text(frame=f, text='KINECT', pos=(0.06985, -0.00635, 0.03175),
         align='center', height=0.0127, depth=0.003)
    return f


_bone_ids = [[0, 1], [1, 2], [2, 3], [7, 6], [6, 5], [5, 4], [4, 2],
             [2, 8], [8, 9], [9, 10], [10, 11], [15, 14], [14, 13], [13, 12],
             [12, 0], [0, 16], [16, 17], [17, 18], [18, 19]]


_kinect = nui.Runtime()
_kinect.skeleton_engine.enabled = True
_kinect.camera.elevation_angle = 0

if __name__ == '__main__':
    draw_sensor(frame())
    skeleton = Skeleton(frame(visible=False))
    ball = sphere(radius=0.1, color=color.red, pos=(-0.5,0.0,0.95))
    ball2 = sphere(radius=0.1, color=color.white, pos=(0.0,0.0,0.95))
    ball3 = sphere(radius=0.1, color=color.orange, pos=(0.5,0.0,0.95))
    msg =  text(text='1. Insira o processo vermelho na CPU', pos=(0.1, 1.15, 0.95),
                 align='center', height=0.1, depth=0.03)
    erro =  text(text='-----------------------', pos=(0.1, 1.0, 0.95),
                 align='center', height=0.1, depth=0.03, color=color.red)
    ordem = 1

    cpu1 = sphere(radius=0.3, color=color.green, pos=(0.0,0.5,0.95))
    estado = text(text='CPU livre', pos=(0.1, 0.85, 0.96),
                 align='center', height=0.1, depth=0.03)
    estadoMaoDireita = 0
    estadoMaoEsquerda = 0
    finalizador = sphere(radius=0.0, color=color.red, pos=(0.0,0.0,0.0))
    while True:
        rate(60)
        skeleton.frame.visible = skeleton.update()


        if(sqrt((skeleton.rightHand.pos.x - ball.pos.x)**2 + (skeleton.rightHand.pos.y - ball.pos.y)**2 + (skeleton.rightHand.pos.z - ball.pos.z)**2) <= 2*ball.radius and estadoMaoEsquerda ==0):
           
            ball.pos.x = skeleton.rightHand.pos.x 
            ball.pos.y = skeleton.rightHand.pos.y 
            ball.pos.z = skeleton.rightHand.pos.z 

            estadoMaoDireita = 1

            

        elif(sqrt((skeleton.leftHand.pos.x - ball.pos.x)**2 + (skeleton.leftHand.pos.y - ball.pos.y)**2 + (skeleton.leftHand.pos.z - ball.pos.z)**2) <= 2*ball.radius and estadoMaoDireita == 0):
            ball.pos.x = skeleton.leftHand.pos.x 
            ball.pos.y = skeleton.leftHand.pos.y 
            ball.pos.z = skeleton.leftHand.pos.z
            estadoMaoEsquerda = 1
            
        else:

            estadoMaoEsquerda = 0
            estadoMaoDireita = 0

        if(sqrt((skeleton.rightHand.pos.x - ball2.pos.x)**2 + (skeleton.rightHand.pos.y - ball2.pos.y)**2 + (skeleton.rightHand.pos.z - ball2.pos.z)**2) <= 2*ball2.radius and estadoMaoEsquerda ==0):
           
            ball2.pos.x = skeleton.rightHand.pos.x 
            ball2.pos.y = skeleton.rightHand.pos.y 
            ball2.pos.z = skeleton.rightHand.pos.z
            estadoMaoDireita = 1
            
            

        elif(sqrt((skeleton.leftHand.pos.x - ball2.pos.x)**2 + (skeleton.leftHand.pos.y - ball2.pos.y)**2 + (skeleton.leftHand.pos.z - ball2.pos.z)**2) <= 2*ball2.radius and estadoMaoDireita==0):
            ball2.pos.x = skeleton.leftHand.pos.x 
            ball2.pos.y = skeleton.leftHand.pos.y 
            ball2.pos.z = skeleton.leftHand.pos.z
            estadoMaoEsquerda = 1
        else:

            estadoMaoEsquerda = 0
            estadoMaoDireita = 0 
        if(sqrt((skeleton.rightHand.pos.x - ball3.pos.x)**2 + (skeleton.rightHand.pos.y - ball3.pos.y)**2 + (skeleton.rightHand.pos.z - ball3.pos.z)**2) <= 2*ball3.radius and estadoMaoEsquerda ==0):
           
            ball3.pos.x = skeleton.rightHand.pos.x 
            ball3.pos.y = skeleton.rightHand.pos.y 
            ball3.pos.z = skeleton.rightHand.pos.z
            estadoMaoDireita = 1
        
            
            

        elif(sqrt((skeleton.leftHand.pos.x - ball3.pos.x)**2 + (skeleton.leftHand.pos.y - ball3.pos.y)**2 + (skeleton.leftHand.pos.z - ball3.pos.z)**2) <= 2*ball3.radius and estadoMaoDireita==0):
            ball3.pos.x = skeleton.leftHand.pos.x 
            ball3.pos.y = skeleton.leftHand.pos.y 
            ball3.pos.z = skeleton.leftHand.pos.z
            estadoMaoEsquerda = 1
        else:

            estadoMaoEsquerda = 0
            estadoMaoDireita = 0   


        if((sqrt((skeleton.rightHand.pos.x - ball.pos.x)**2 + (skeleton.rightHand.pos.y - ball.pos.y)**2 + (skeleton.rightHand.pos.z - ball.pos.z)**2) <= 2*ball.radius) or
        (sqrt((skeleton.leftHand.pos.x - ball.pos.x)**2 + (skeleton.leftHand.pos.y - ball.pos.y)**2 + (skeleton.leftHand.pos.z - ball.pos.z)**2) <= 2*ball.radius)):

            if(sqrt((ball.pos.x - cpu1.pos.x)**2 + (ball.pos.y- cpu1.pos.y)**2 + (ball.pos.z- cpu1.pos.z)**2) <= cpu1.radius):
                if ordem==1:#e for a vez dela entrar
                    cpu1.color = color.blue
                    estado.text = 'CPU ocupada'
                    erro.text = "Processando..."
                    msg.text = "2. Insira o processo branco"
                    ball.opacity = 0.0
                    ball.radius = 0.0
                    ball.pos.x = 0.0
                    ball.pos.y = 0.0
                    ball.pos.z = 0.0
                    ordem = 2
                else: 
                    erro.text = "Processo inválido"   

        if((sqrt((skeleton.rightHand.pos.x - ball2.pos.x)**2 + (skeleton.rightHand.pos.y - ball2.pos.y)**2 + (skeleton.rightHand.pos.z - ball2.pos.z)**2) <= 2*ball2.radius) or
        (sqrt((skeleton.leftHand.pos.x - ball2.pos.x)**2 + (skeleton.leftHand.pos.y - ball2.pos.y)**2 + (skeleton.leftHand.pos.z - ball2.pos.z)**2) <= 2*ball2.radius)):

            if(ordem == 2):
                cpu1.color = color.green
                estado.text = "CPU livre"
                erro.text = "-----------------------"
                

            if(sqrt((ball2.pos.x - cpu1.pos.x)**2 + (ball2.pos.y- cpu1.pos.y)**2 + (ball2.pos.z- cpu1.pos.z)**2) <= cpu1.radius):
                if ordem==2:#e for a vez dela entrar
                    cpu1.color = color.blue
                    estado.text = 'CPU ocupada'
                    erro.text = "Processando..."
                    msg.text = "3. Insira o processo laranja"
                    ball2.opacity = 0.0
                    ball2.radius = 0.0
                    ball2.pos.x = 0.0
                    ball2.pos.y = 0.0
                    ball2.pos.z = 0.0
                    ordem = 3
                else: 
                    erro.text = "Processo inválido"        

        if((sqrt((skeleton.rightHand.pos.x - ball3.pos.x)**2 + (skeleton.rightHand.pos.y - ball3.pos.y)**2 + (skeleton.rightHand.pos.z - ball3.pos.z)**2) <= 2*ball3.radius) or
        (sqrt((skeleton.leftHand.pos.x - ball3.pos.x)**2 + (skeleton.leftHand.pos.y - ball3.pos.y)**2 + (skeleton.leftHand.pos.z - ball3.pos.z)**2) <= 2*ball3.radius)):

            if(ordem == 3):
                cpu1.color = color.green
                estado.text = "CPU livre"
                erro.text = "-----------------------"
                

            if(sqrt((ball3.pos.x - cpu1.pos.x)**2 + (ball3.pos.y- cpu1.pos.y)**2 + (ball3.pos.z- cpu1.pos.z)**2) <= cpu1.radius):
                if ordem==3:#e for a vez dela entrar
                    cpu1.color = color.blue
                    estado.text = 'CPU ocupada'
                    erro.text = "Processando..."
                    ball3.opacity = 0.0
                    ball3.radius = 0.0
                    ball3.pos.x = 0.0
                    ball3.pos.y = 0.0
                    ball3.pos.z = 0.0
                    ordem = 4
                else: 
                    erro.text = "Processo inválido"      
        if(ordem == 4):
             estado.text = 'CPU livre'
             cpu1.color = color.green
             erro.text = "-----------------------"
            #finalizador.pos.x = 0.0
             #finalizador.pos.y = -0.50
             #finalizador.pos.z = 0.95
             #finalizador.radius = 0.2
             msg.text = "Programa finalizado com sucesso!"
            
    
