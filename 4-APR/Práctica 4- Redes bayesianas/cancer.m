N=5;
P=1;
F=2;
C=3;
X=4;
D=5;
grafo=zeros(N,N);
grafo([P F],C)=1;
grafo(C,X)=1;
grafo(C,D)=1;

nodosDiscretos=1:N;
tallaNodos=[2 2 2 3 2];

redB = mk_bnet(grafo, tallaNodos, 'discrete',nodosDiscretos);

redB.CPD{P} = tabular_CPD(redB, P, [0.9 0.1]);
redB.CPD{F} = tabular_CPD(redB, F, [0.7 0.3]);
redB.CPD{C} = tabular_CPD(redB, C, [0.999 0.97 0.95 0.92 0.001 0.03 0.05 0.08]);
redB.CPD{X} = tabular_CPD(redB, X, [0.8 0.1 0.1 0.2 0.1 0.7]);
redB.CPD{D} = tabular_CPD(redB, D, [0.7 0.35 0.3 0.65]);

motor = jtree_inf_engine(redB);

% apartado b
evidencia = cell(1,N);
evidencia{F}=1;
evidencia{X}=1;
evidencia{D}=2;
[motor, logVerosim] = enter_evidence(motor, evidencia);
m = marginal_nodes(motor, C);
m.T

% apartado c
motor = jtree_inf_engine(redB);
evidencia2 = cell(1,N);
evidencia2{C}=2;
[explMaxProb, logVerosim] = calc_mpe(motor, evidencia2);
explMaxProb
