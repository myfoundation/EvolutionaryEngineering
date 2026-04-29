  LABEL   0  
  SET_S   0  
  LABEL   1  
  LD_IN  
  JMP_IF  77 , 8  
  JMP_IF  86 , 9  
  JMP_IF  84 , 10 
  JMP_IF  80 , 11 
  JMP_IF  79 , 12 
  JMP     1  
  LABEL   8  
  EXEC    0  
  JMP     2  
  LABEL   9  
  EXEC    3  
  JMP     6  
  LABEL   10 
  EXEC    4  
  JMP     0  
  LABEL   11 
  EXEC    2  
  JMP     0  
  LABEL   12 
  EXEC    4  
  JMP     0  
  LABEL   2  
  SET_S   1  
  LABEL   3  
  LD_IN  
  JMP_IF  77 , 13 
  JMP_IF  86 , 14 
  JMP_IF  84 , 15 
  JMP_IF  80 , 16 
  JMP_IF  79 , 17 
  JMP     3  
  LABEL   13 
  EXEC    0  
  JMP     4  
  LABEL   14 
  EXEC    3  
  JMP     6  
  LABEL   15 
  EXEC    1  
  JMP     0  
  LABEL   16 
  EXEC    2  
  JMP     2  
  LABEL   17 
  EXEC    7  
  JMP     0  
  LABEL   4  
  SET_S   2  
  LABEL   5  
  LD_IN  
  JMP_IF  77 , 18 
  JMP_IF  86 , 19 
  JMP_IF  84 , 20 
  JMP_IF  80 , 21 
  JMP_IF  79 , 22 
  JMP     5  
  LABEL   18 
  EXEC    5  
  JMP     0  
  LABEL   19 
  EXEC    3  
  JMP     6  
  LABEL   20 
  EXEC    1  
  JMP     0  
  LABEL   21 
  EXEC    2  
  JMP     4  
  LABEL   22 
  EXEC    7  
  JMP     0  
  LABEL   6  
  SET_S   3  
  LABEL   7  
  LD_IN  
  JMP_IF  77 , 23 
  JMP_IF  86 , 24 
  JMP_IF  84 , 25 
  JMP_IF  80 , 26 
  JMP_IF  79 , 27 
  JMP     7  
  LABEL   23 
  EXEC    6  
  JMP     6  
  LABEL   24 
  EXEC    6  
  JMP     6  
  LABEL   25 
  EXEC    6  
  JMP     6  
  LABEL   26 
  EXEC    6  
  JMP     6  
  LABEL   27 
  EXEC    6  
  JMP     6  
  HALT   
