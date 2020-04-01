% Definicion de las variables para la matriz de adyacencia 
N=4;
C=1;
S=2;
R=3;
W=4;
grafo=zeros(N,N);
grafo(C,[R S])=1;
grafo(R,W)=1;
grafo(S,W)=1;

% Definicion de los parametros del grafo
nodosDiscretos=1:N;
% 2 porque solo pueden ser true o false
tallaNodos=2*ones(1,N);

% creacion de la red bayesiana
redB = mk_bnet(grafo,tallaNodos,'discrete',nodosDiscretos);

% deficion distrubicion probabilidad condicionada
redB.CPD{W} = tabular_CPD(redB, W, [1.0 0.1 0.1 0.01 0.0 0.9 0.9 0.99]);
redB.CPD{C} = tabular_CPD(redB, C, [0.5 0.5]);
redB.CPD{S} = tabular_CPD(redB, S, [0.5 0.9 0.5 0.1]);
redB.CPD{R} = tabular_CPD(redB, R, [0.8 0.2 0.2 0.8]);


% deficion motor inferencia
motor=jtree_inf_engine(redB);

% creacion de las muestras aleatorias
semilla=0;
rng(semilla);
nMuestras=1000;
muestras=cell(N,nMuestras);
for i=1:nMuestras
    muestras(:,i)=sample_bnet(redB);
end

% creacion de las muestras ocultas
muestrasS=muestras;
rng(semilla);
ocultas=rand(N,nMuestras)>0.5;
[I,J]=find(ocultas);
for k=1:length(I)
    muestrasS{I(k),J(k)}=[];
end


% definicion de otra red para calcular las muestras
redEM = mk_bnet(grafo, tallaNodos, 'discrete', nodosDiscretos);
redEM.CPD{C} = tabular_CPD(redEM, C);
redEM.CPD{R} = tabular_CPD(redEM, R);
redEM.CPD{S} = tabular_CPD(redEM, S);
redEM.CPD{W} = tabular_CPD(redEM, W);
motorEM      = jtree_inf_engine(redEM);

% aprender los parametros
maxIter = 200; 
eps = 1e-4;
rng(semilla);
[redEM2, trazaLogVer] = learn_params_em(motorEM, muestrasS, maxIter, eps);


% modificar la estructura para ser visible
TPCaux=cell(1,N);
for i=1:N
    s=struct(redEM2.CPD{i});
    TPCaux{i}=s.CPT;
end

% visualizacion de los datos
disp("La variable C:");
dispcpt(TPCaux{C});
disp("La variable S:");
dispcpt(TPCaux{S});
disp("La variable R:");
dispcpt(TPCaux{R});
disp("La variable W:");
dispcpt(TPCaux{W});



