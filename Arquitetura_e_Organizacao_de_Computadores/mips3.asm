.text
 
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
   
   li $v0, 32 #sleep
   li $a0, 10 #20ms
   syscall #do the sleep
   
 
   blt $s3, $t7, DrawPixel #draws a pixel, and deletes the tail
   j end 

 
DrawPixel:
 
addi $s0, $s0, 1         #adds 1 to the X of the head
li $t3, 0x10000100       #t3 = first Pixel of the screen
 
sll   $t0, $s3, 9        #y = y * 512
addu  $t0, $t0, $s0      # (xy) t0 = x + y
sll   $t0, $t0, 2        # (xy) t0 = xy * 4
addu  $t0, $t3, $t0      # adds xy to the first pixel ( t3 )
sw    $a2, ($t0)         # put the color red ($a2) in $t0
 

j loop                   #goes back to the drawing loop
 

end:
 
    ####exit########
    li $v0, 10
    syscall