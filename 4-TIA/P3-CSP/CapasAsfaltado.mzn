% Use this editor as a MiniZinc scratch book
include "alldifferent.mzn";


array [1..18] of var 1..18: capa;
%capa[1-9] pertenece a tipo A, capa[10-18] pertenece a tipo B

constraint alldifferent(capa);

%regla a
%capa[2] 1,5,9,13
%abs(capa[2]-capa[j])>1
constraint abs(capa[2]-capa[1])>1;
constraint abs(capa[2]-capa[5])>1;
constraint abs(capa[2]-capa[9])>1;
constraint abs(capa[2]-capa[13])>1;

%regla b
constraint forall (i in 1..9 where i!=7) (abs(capa[7]-capa[i])!=1);

%regla c
constraint abs(capa[4]-capa[13])>=5;

%regla d
constraint abs(capa[8]-capa[17])=2;

%regla e
constraint abs(capa[5]-capa[14])=1;

%regla f
constraint abs(capa[4]-capa[1])=1 \/ abs(capa[4]-capa[10])=1 \/ abs(capa[4]-capa[9])=1 \/ abs(capa[4]-capa[18])=1;

%regla g
constraint abs(capa[6]-capa[7])!=1;

%regla h
constraint abs(capa[5]-capa[13])=1 \/ abs(capa[5]-capa[17])=1 \/ abs(capa[5]-capa[2])=1 \/ abs(capa[5]-capa[3])=1 \/ abs(capa[5]-capa[7])=1;
constraint abs(capa[14]-capa[6])!=1;

%regla i
constraint forall (i,j in 1..9 where i<j) (capa[i] < capa[j]);

%regla j
constraint forall (i,j in 10..15 where i<j) (capa[i] > capa[j]);

%solucion 1
solve satisfy;

%solucion 2
%solve minimize abs(capa[8]-capa[9]) + abs(capa[10]-capa[11]);

%solucion 3
%solve minimize (abs(capa[7]-capa[16]) / abs(capa[3]-capa[18]));