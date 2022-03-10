#include<bits/stdc++.h>
#include<Windows.h>
using namespace std;
float a[100][100],b[100][100],c[100][100],tem1,tem2,tem3;
int require,nexty;
int jc_hang,jc_lie;
bool cte=false;
void chengfa()//乘法函数
{
    int m,n,i,j,ch;
    if(cte)
    {
        m=jc_hang,n=jc_lie;
        cout<<"请选择："<<endl;
        cout<<"1.先位乘法(新矩阵在后)"<<endl;
        cout<<"2.后位乘法(新矩阵在前)"<<endl;
        cin>>ch;
        if(ch==1)
        {
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    a[i][j]=c[i][j];
                }
            }
            cout<<"请输入合法的新矩阵行列数"<<endl;
            cin>>i>>j;
            while(i!=n)
            {
                cout<<"无法相乘，请重新输入"<<endl;
                cin>>i>>j;
            }
            cout<<"请输入矩阵："<<endl;
            for(int x=1;x<=i;x++)for(int y=1;y<=j;y++)cin>>b[x][y];
        }
        else
        {
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    b[i][j]=c[i][j];
                }
            }
            cout<<"请输入合法的新矩阵行列数"<<endl;
            cin>>i>>j;
            while(j!=m)
            {
                cout<<"无法相乘，请重新输入"<<endl;
                cin>>i>>j;
            }
            cout<<"请输入矩阵："<<endl;
            for(int x=1;x<=i;x++)for(int y=1;y<=j;y++)cin>>a[x][y];
        }
    }
    else 
    {
        cout<<"请输入矩阵1行列数"<<endl;
        cin>>m>>n;
        if(!(m&&n))
        {
            cout<<"输入错误"<<endl<<"退出"<<endl;
            return;
        }
        for(int x=1;x<=m;x++)for(int y=1;y<=n;y++)cin>>a[x][y];
        cout<<"请输入矩阵2行列数"<<endl;
        cin>>i>>j;
        while(i!=n)
        {
            cout<<"无法相乘，请重新输入"<<endl;
            cin>>i>>j;
        }
        for(int x=1;x<=i;x++)for(int y=1;y<=j;y++)cin>>b[x][y];
    }
    for(int x=1;x<=m;x++)
    {
        for(int y=1;y<=j;y++)
        {
            float tmp=0;
            for(int z=1;z<=i;z++)
            {
                tmp+=a[x][z]*b[z][y];
            }
            c[x][y]=tmp;
        }
    }
    cout<<"运算结果为："<<endl;
    jc_hang=m,jc_lie=j;
    for(int x=1;x<=m;x++)
    {
        for(int y=1;y<=j;y++)
        {
            if(fabs(c[x][y])<1.e-06)c[x][y]=0;
            cout<<c[x][y]<<" ";
        }
        cout<<endl<<endl;
    }
    cout<<endl;
}
void chengfang()//乘方函数
{
    int m,n,tim;
    cout<<"请输入矩阵行列数"<<endl;
    cin>>m>>n;
    if(!(m&&n)||m!=n)
    {
        cout<<"输入错误"<<endl<<"退出"<<endl;
        return;
    }
    cout<<"请输入矩阵："<<endl;
    for(int x=1;x<=m;x++)for(int y=1;y<=n;y++)
    {
        cin>>a[x][y];
        c[x][y]=b[x][y]=a[x][y];
    }
    cout<<"请输入幂次"<<endl;
    cin>>tim;
    while(--tim)
    {
            for(int x=1;x<=m;x++)
        {
            for(int y=1;y<=n;y++)
            {
                int tmp=0;
                for(int z=1;z<=n;z++)
                {
                    tmp+=a[x][z]*b[z][y];
                }
                c[x][y]=tmp;
            }
        }
        for(int x=1;x<=m;x++)for(int y=1;y<=n;y++)a[x][y]=c[x][y];
    }
    cout<<"运算结果为："<<endl;
    for(int x=1;x<=m;x++)
    {
        for(int y=1;y<=n;y++)
        {
            if(fabs(c[x][y])<1.e-06)c[x][y]=0;
            cout<<c[x][y]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
void gaosiqiuni()//求逆矩阵
{
    int m,n;
    cout<<"请输入矩阵行列数"<<endl;
    cin>>m>>n;
    if(!(m&&n)||m!=n)
    {
        cout<<"输入错误"<<endl<<"退出"<<endl;
        return;
    }
    cout<<"请输入矩阵："<<endl;
    for(int x=1;x<=m;x++)for(int y=1;y<=n;y++)cin>>a[x][y];
    for(int x=1;x<=m;x++)for(int y=n+1;y<=2*n;y++)//扩增矩阵
    {
        if(y-x==n)a[x][y]=1.;
    }
    for(int x=1,y;x<=n;x++)//创建阶梯矩阵
    {
        if((a[x][x])==0.)
        {
            for(y=x+1;y<=n;y++)
            {
                if((a[y][x])!=0.)break;
            }
            if(y>n)
            {
                cout<<"此矩阵不能求逆"<<endl;
                return;
            }
            for(int k=1;k<=2*n;k++)a[x][k]+=a[y][k];
        }
        tem1=a[x][x];
        for(int j=1;j<=2*n;j++)a[x][j]/=tem1;
        for(int j=x+1;j<=n;j++)
        {
            tem2=a[j][x];
            for(int k=1;k<=2*n;k++)a[j][k]-=tem2*a[x][k];
        }
    }
    for(int i=n;i>0;i--)
    {
        for(int j=i-1;j>0;j--)
        {
            tem3=a[j][i];
            for(int k=i;k<=2*n;k++)
            {
                a[j][k]-=tem3*a[i][k];
            }
        }
    }
    cout<<"逆矩阵结果为："<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=n+1;j<=2*n;j++)
        {
            if(fabs(a[i][j])<1.e-06)a[i][j]=0;
            cout<<a[i][j]<<" ";
            c[i][j-n]=a[i][j];
        }
        cout<<endl<<endl;
    }
    jc_hang=m,jc_lie=n;
}
int main()
{
    cout<<"欢迎来到菜鸡自助矩阵运算系统"<<endl;
    while(1)
    {
        cte=false;
        cout<<"请输入指令"<<endl;
        cout<<"1.矩阵相乘"<<endl;
        cout<<"2.矩阵乘方"<<endl;
        cout<<"3.矩阵求逆"<<endl;
        cout<<"4.退出系统"<<endl;
        cin>>require;
        if(!(require-1))
        {
            cout<<"请选择："<<endl;
            cout<<"1.继承乘法"<<endl;
            cout<<"2.新的乘法"<<endl;
            cin>>nexty;
            if(!(nexty-1))cte=true;
            chengfa();
        }
        if(!(require-2))chengfang();
        if(!(require-3))gaosiqiuni();
        if(!(require-4))break;
    }
    cout<<"滚吧，废物"<<endl;
    return 0;
}
