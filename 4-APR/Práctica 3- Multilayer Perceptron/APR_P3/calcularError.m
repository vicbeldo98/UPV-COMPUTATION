
function [error] = calcularError (simOut, labels_corres)
error=0;
nMuestras=columns(simOut);
for i=1:1:nMuestras
  [~,clase]=max(simOut(:,i));
  if(labels_corres(i)!=clase) 
    error+=1;
    endif
endfor
error=error/nMuestras
endfunction
