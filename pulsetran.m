t = 0 : 1/1e6 : .01;         
d = 0 : 1/50e3 : .01;           
y = pulstran(t,d,@rectpuls);
plot(t,y); 
axis([0 0.001 0 1.5])
