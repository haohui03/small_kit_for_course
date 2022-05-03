from cgi import print_arguments


print('三电压表法:')
i=1
while(i):
    u1=float(input('输入u1: '))
    u2=float(input('输入u2: '))
    u3=float(input('输入u3: '))
    i=u2/200
    z=u3/i
    cosr=(u1**2-u2**2-u3**2)/(2*u2*u3)
    print('输出z: %.4f'%z)
    print('输出cos:%.4f'%cosr)
    a=int(input('1:白炽灯,2:镇流器,2:电容器: '))
    if(a==1):
        print('输出等效电阻：%.3f'%(cosr*z))    
    elif(a==2):
        print('输出等效电阻：%.3f'%(cosr*z))
        print('输出等效参数L:%.3f'%(z*(1-cosr**2)**0.5/(2*3.14*50)))
    else:
        print('输出等效参数C%.7f'%(1/(z*(1-cosr**2)**0.5*2*3.14*50)))
    i=int(input('1:继续,0:结束'))
print('Thank you')