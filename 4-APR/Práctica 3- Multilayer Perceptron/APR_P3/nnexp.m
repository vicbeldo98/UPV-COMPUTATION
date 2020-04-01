
function [error] = nnexp (tr,trlabels,ts,tslabels,nHidden,nOutput,nCapas)
addpath('nnet');
%Los transponemos porque nnet trabaja con las samples por columnas
mInput= tr';
mOutput=trlabels';
mTestInput=ts';
mTestOutput=tslabels';
%Cogemos un 80% de datos aleatorios para training, y un 20% para validacion
[nFeat, nSamples] = size(mInput);
nTr=floor(nSamples*0.8);
nVal=nSamples-nTr;
rand('seed',23);
indices=randperm(nSamples);
mTrainInput=mInput(:,indices(1:nTr));
mTrainOutput=mOutput(indices(1:nTr));
mValiInput=mInput(:,indices((nTr+1):nSamples));
mValiOutput=mOutput(indices((nTr+1):nSamples));

%Cambiamos a one-hot encoding las etiquetas de clase
filas=rows(unique(trlabels));
columnas=nTr;
mTrainOutputResult=zeros(filas,columnas);
for i=1:1:columnas
  clase=mTrainOutput(i);
  mTrainOutputResult(clase,i)=1;
endfor
filas=rows(unique(tslabels));
columnas=nSamples-nTr;
mValidOutputResult=zeros(filas,columnas);
for i=1:1:columnas
  clase=mValiOutput(i);
  mValidOutputResult(clase,i)=1;
endfor

%Normalizar los datos
[mTrainInputN,cMeanInput,cStdInput] = prestd(mTrainInput);
 
%Estructura especial para los datos de validacion
 VV.P = mValiInput;
 VV.T = mValidOutputResult;
%Normalizar datos validacion
VV.P = trastd(VV.P,cMeanInput,cStdInput);

%Especificar red neuronal
%Pr es una matriz Dx2 con los valores maximo y minimo en cada dimension
%ss un vector fila con el numero de neuronas en cada capa oculta y en la capa de salida
%trf es la lista de funciones de activacion de cada capa
%btf algoritmo de entrenamiento de la red neuronal : trainlm (backpropagation)
%blf parametro no usado actualmente
%pf es la funcion objetivo a minimizar: mse (error cuadratico medio)
%net= newff (Pr,ss,trf,btf,blf,pf);
vector_capas_neuronas=[];
funciones={};
for i=1:nCapas
  vector_capas_neuronas=[vector_capas_neuronas nHidden];
  funciones(i)="tansig";
endfor
funciones(nCapas+1)="logsig";
  vector_capas_neuronas=[vector_capas_neuronas nOutput];
MLPnet = newff(minmax(mTrainInputN),vector_capas_neuronas,funciones,"trainlm","","mse");
 
%el parametro show indica cada cuantas epochs de entrenamiento queremos que
%se imprima informacion, y el parametro epochs es el numero maximo de epochs que
%queremos que realice, adicionalmente al criterio de parada del conjunto de validacion.
MLPnet.trainParam.show = 10;
MLPnet.trainParam.epochs = 300;

%Entrenar la red neuronal
net = train(MLPnet,mTrainInputN,mTrainOutputResult,[],[],VV);

%Normalizar conjunto de test
mTestInputN=trastd(mTestInput,cMeanInput,cStdInput);

%Clasificar los datos
simOut= sim(net,mTestInputN);

error=calcularError(simOut,mTestOutput);

endfunction
