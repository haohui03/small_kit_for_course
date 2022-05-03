print('三表法:')
i=1
while(i):
    u=float(input('输入U: '))
    i=float(input('输入I: '))
    p=float(input('输入p: '))
    z=u/i
    print(f"输出z:{z}")
    cosr=p/(u*i)
    print('输出cos:%.3f'%cosr)
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

