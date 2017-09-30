.text

######Desenhando um retangulo#####

li $a2, 0x00FF0000  #loads the color red into the register $a2
li $s3, 50          #y1 = y position of the tail
li $s0, 50          #x2 = x position of the head
 
addi $t6, $s0, 50
addi $t7, $s3, 10

loop:
   blt $s0, $t6, DrawPixel # while the head isnt in the first limit (100) draws a pixel in (s0,s1)
   addi $s3, $s3, 1
   
 
loop2:
   li $s2,  50         #x1 = x position of the tail
   li $s0, 50         #y2 = y position of the head  
 
   blt $s3, $t7, DrawPixel #draws a pixel, and deletes the tail
   j

 
DrawPixel:
 
addi $s0, $s0, 1         #adds 1 to the X of the head
li $t3, 0x10000100       #t3 = first Pixel of the screen
 
sll   $t0, $s3, 9        #y = y * 512
addu  $t0, $t0, $s0      # (xy) t0 = x + y
sll   $t0, $t0, 2        # (xy) t0 = xy * 4
addu  $t0, $t3, $t0      # adds xy to the first pixel ( t3 )
sw    $a2, ($t0)         # put the color red ($a2) in $t0

j loop                   #goes back to the drawing loop


######Desenhando a barra#########

li $a2, 0x00FFFFFF  # Carregando a cor branca para o registrador a2
li $s1, 280         # y1 = y posicao final da barra
li $s0, 50          # x1 = x posicao inicial da barra
 
li $t6, 100         # Limite de x para pintar a barra
 
loop3:
   blt $s0, $t6, DrawPixel3 # Enquanto o inicio nao atingiu o limite (100) pinta os pixels em (s0, s1)
   j end                    # Finaliza o programa
 
DrawPixel3:
 
addi $s0, $s0, 1         # Adiciona 1 em x inicial
li $t3, 0x10000100       # t3 = primeiro pixel da tela
 
sll   $t0, $s1, 9        # y = y * 512
addu  $t0, $t0, $s0      # (xy) t0 = x + y
sll   $t0, $t0, 2        # (xy) t0 = xy * 4
addu  $t0, $t3, $t0      # Adiciona xy ao primeiro pixel ( t3 )
sw    $a2, ($t0)         # Coloca a cor branca ($a2) em $t0

j loop3                  # Volta para o loop de desenho

end:
 
    ####Sai do programa########
    li $v0, 10
    syscall