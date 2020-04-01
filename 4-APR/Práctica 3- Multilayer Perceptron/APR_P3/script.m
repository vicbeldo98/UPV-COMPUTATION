%Cargamos los datos
load("data/hart/tr.dat");
load("data/hart/trlabels.dat");
load("data/hart/ts.dat");
load("data/hart/tslabels.dat");

err =nnexp(tr,trlabels,ts,tslabels,1,2);
err2=nnexp(tr,trlabels,ts,tslabels,2,2);
err5 =nnexp(tr,trlabels,ts,tslabels,5,2);

printf("Porcentaje de aciertos con una neuronas en la capa oculta: %.3f\n",err);
printf("Porcentaje de aciertos con dos neuronas en la capa oculta: %.3f\n",err2);
printf("Porcentaje de aciertos con cinco neuronas en la capa oculta: %.3f\n",err5);
