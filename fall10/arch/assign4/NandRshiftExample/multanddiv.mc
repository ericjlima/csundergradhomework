0:mar := pc; rd; 				{ main loop  }
1:pc := 1 + pc; rd; 				{ increment pc }
2:ir := mbr; if n then goto 28; 		{ save, decode mbr }
3:tir := lshift(ir + ir); if n then goto 19; 	
4:tir := lshift(tir); if n then goto 11; 	{ 000x or 001x? }
5:alu := tir; if n then goto 9; 		{ 0000 or 0001? }
6:mar := ir; rd; 				{ 0000 = LODD }
7:rd; 						
8:ac := mbr; goto 0; 				
9:mar := ir; mbr := ac; wr; 			{ 0001 = STOD }
10:wr; goto 0; 					
11:alu := tir; if n then goto 15; 		{ 0010 or 0011? }
12:mar := ir; rd; 				{ 0010 = ADDD }
13:rd; 						
14:ac := ac + mbr; goto 0; 			
15:mar := ir; rd; 				{ 0011 = SUBD }
16:ac := 1 + ac; rd; 				{ Note: x - y = x + 1 + not y }
17:a := inv(mbr); 				
18:ac := a + ac; goto 0; 			
19:tir := lshift(tir); if n then goto 25; 	{ 010x or 011x? }
20:alu := tir; if n then goto 23; 		{ 0100 or 0101? }
21:alu := ac; if n then goto 0; 		{ 0100 = JPOS }
22:pc := band(ir, amask); goto 0; 		{ perform the jump }
23:alu := ac; if z then goto 22; 		{ 0101 = JZER }
24:goto 0;					{ jump failed }
25:alu := tir; if n then goto 27; 		{ 0110 or 0111? }
26:pc := band(ir, amask); goto 0; 		{ 0110 = JUMP }
27:ac := band(ir, amask); goto 0; 		{ 0111 = LOCO }
28:tir := lshift(ir + ir); if n then goto 40; 	{ 10xx or 11xx? }
29:tir := lshift(tir); if n then goto 35; 	{ 100x or 101x? }
30:alu := tir; if n then goto 33; 		{ 1000 or 1001? }
31:a := sp + ir; 				{ 1000 = LODL }
32:mar := a; rd; goto 7; 			
33:a := sp + ir; 				{ 1001 = STOL }
34:mar := a; mbr := ac; wr; goto 10; 		
35:alu := tir; if n then goto 38; 		{ 1010 or 1011? }
36:a := sp + ir; 				{ 1010 = ADDL }
37:mar := a; rd; goto 13; 			
38:a := sp + ir; 				{ 1011 = SUBL }
39:mar := a; rd; goto 16; 			
40:tir := lshift(tir); if n then goto 46; 	{ 110x or 111x? }
41:alu := tir; if n then goto 44; 		{ 1100 or 1101? }
42:alu := ac; if n then goto 22; 		{ 1100 = JNEG }
43:goto 0; 					
44:alu := ac; if z then goto 0; 		{ 1101 = JNZE }
45:pc := band(ir, amask); goto 0; 		
46:tir := lshift(tir); if n then goto 50; 	
47:sp := sp + (-1); 				{ 1110 = CALL }
48:mar := sp; mbr := pc; wr; 			
49:pc := band(ir, amask); wr; goto 0; 		
50:tir := lshift(tir); if n then goto 65; 	{ 1111, examine addr }
51:tir := lshift(tir); if n then goto 59; 	
52:alu := tir; if n then goto 56; 		
53:mar := ac; rd; 				{ 1111000 = PSHI }
54:sp := sp + (-1); rd; 			
55:mar := sp; wr; goto 10; 			
56:mar := sp; sp := sp + 1; rd; 		{ 1111001 = POPI }
57:rd; 						
58:mar := ac; wr; goto 10; 			
59:alu := tir; if n then goto 62; 		
60:sp := sp + (-1); 				{ 1111010 = PUSH }
61:mar := sp; mbr := ac; wr; goto 10; 		
62:mar := sp; sp := sp + 1; rd; 		{ 1111011 = POP }
63:rd; 						
64:ac := mbr; goto 0; 				
65:tir := lshift(tir); if n then goto 73; 	
66:alu := tir; if n then goto 70; 		
67:mar := sp; sp := sp + 1; rd; 		{ 1111100 = RETN }
68:rd; 						
69:pc := mbr; goto 0; 				
70:a := ac; 					{ 1111101 = SWAP }
71:ac := sp; 					
72:sp := a; goto 0; 				
73:alu := tir; if n then goto 76; 		
74:a := band(ir, smask); 			{ 1111110 = INSP }
75:sp := sp + a; goto 0; 			
76:tir := tir + tir; if n then goto 80;		
77:a := band(ir, smask); 			{ 11111110 = DESP }
78:a := inv(a); 				
79:a := a + 1; goto 75; 			
80:tir := tir + tir; if n then goto 97;		{ 1111 1111 1x = HALT }
81:alu := tir + tir; if n then goto 89;         { 1111 1111 01 = RSHIFT }
82:mar := sp; rd;			        { MULT }
83:c := 0;rd;
84:a := mbr;if n then goto(neg stack);          {stackpt}
85:b := mbr; 
86:ac := band(ir, smask);
87:ac := ac + (-1): if z goto(done);            {loop}
88:a := a + b; if n goto(ovflw);
89:goto loop;
90:mbr := inv(mbr);                             {neg stack }
91:mbr := mbr + 1;
92:c:= 1; goto (stackpt);
93:a:=inv(a);                                   {negrslt}
94:a:=a + 1; goto(done + 1);
95:c := c + (-1); if z then goto(negrslt);      {done}
96:mbr:= a; wr;
97:wr :goto 0;
98:ac:=(-1);                                     {this accounts for overflow}
99:mbr:= b; wr;
100:wr; goto 0;
101:mar:= sp; rd;                                {divide function is here}
102:d:=0;rd;
103:b:= mbr; if n then goto (neg divdnd);                 
104:mar:= sp + 1 ; rd; 
105:rd;
106:a:=mbr; if z then goto (divisor = 0);
107:alu:= a; if n then goto(divisor > dividend)
108:c:=1;
109:b:=b + a; if n then goto (done);            {start of my loop}
110:c:= c + 1; goto (loop) ;
111:mbr:= inv(mbr) ;                             {accounts for negative dividend}
112:mbr:=mbr+1;
113: d:=d+1; goto(rtnpt1);
114: d:=d+1; goto(pt2);                                     
115:a:=inv(a);                                  {negative divisor, finished with loop}
116:a:=a+1;
117:mbr:=b+a;
118:sp:=sp+(-1);
119:mar:=sp;wr;
120:sp:=sp+(-1);wr;
121:d:=d+(-1) if z goto (neg reslt);
122:mar:= sp; mbr:c;wr;                       
123:ac:=;wr; goto 0;
124:c:= inv(c);                                    
125:c:= c + 1; goto (pt3);
126:a:=inv(a);                                  
127:a:=a+1;
128:sp:=sp+(-1);
129:mar:=sp;mbr:=a;wr;
130:sp:=sp+(-1);wr;
131:mar:=sp;mbr;=0;wr;
132:ac:=0;wr;goto 0;
133:sp:=sp+(-1)                                {if the divisor = 0}
134:mar:=sp;mbr:=(-1);wr;
135:sp:=sp+(-1);wr;
136:mar:=sp;mbr:=0;wr;
137:ac:=(-1);wr;goto 0;

