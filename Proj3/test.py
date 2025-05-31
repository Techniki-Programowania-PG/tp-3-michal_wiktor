import proj3

signal = [5,6,8]
filter=[-1,0,1]
result = proj3.DF(signal, filter)
print(result)
proj3.showSig(result)
signal1=proj3.sinGen(50, 1000,5)
proj3.showSig(signal1)
transform = proj3.DFT(signal1)
proj3.showTransf(transform, 1000)
untransform=proj3.rDFT(transform)
proj3.showSig(untransform)
signal2=proj3.cosGen(10, 1000, 5)
proj3.showSig(signal2)  
signal3=proj3.recGen(5, 1000, 5)
proj3.showSig(signal3)
signal4=proj3.sawGen(5, 1000, 5)
proj3.showSig(signal4)
