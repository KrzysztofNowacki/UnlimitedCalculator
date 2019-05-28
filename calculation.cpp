#include <iostream>
#include <string>
int math{};

std::string revers(std::string a)
{
    std::string rev{};
    for(long long i=a.size()-1;i>=0;i--)
    {
        rev=rev+a[i];
    }
    return rev;
}

std::string main_sub(std::string a, std::string b)
{
    std::string rest{};
    a=revers(a);
    b=revers(b);
    int r{};
    char add[1]{};
    for(unsigned long i{};i<a.size();i++)
    {
        if(b[i]<'0'&&a[i]>='0'&&r==0)
        {
            a.erase(0,i);
            rest+=a;
            break;
        }
        else if(b[i]<'0'&&a[i]>'0'&&r==1)
        {
            int h=a[i];
            h-=r;
            add[0]=h;
            r=0;
        }
        else if(b[i]<'0'&&a[i]=='0'&&r==1)
        {
            add[0]=9;
            r=1;
        }
        else if(b[i]+r>a[i])
        {
            int hb=b[i]-'0',ha=a[i]-'0';
            hb=hb-ha+r;
            add[0]=10-hb+'0';
            r=1;
        }
        else
        {
            int hb=b[i]-'0',ha=a[i]-'0';
            ha=ha-hb-r;
            add[0]=ha+'0';
            r=0;
        }
        rest+=add[0];
    }
    rest=revers(rest);
    for(unsigned long i{};i<rest.size();i++)
    {
        if(rest[i]!='0'){rest.erase(0,i);break;}
    }
    return rest;
}

std::string main_add(std::string a, std::string b)
{
    std::string sum{};
    a=revers(a);
    b=revers(b);
    unsigned long n=a.size();
    if(a.size()<b.size())n=b.size();
    int r{};
    for(unsigned long i{};i<n;i++)
    {
        int c{};
        if(i>a.size()-1) c=b[i]-'0'+r;
        else if(i>b.size()-1) c=a[i]-'0'+r;
        else c=a[i]-'0'+b[i]-'0'+r;
        if(c>9){r=1;c%=10;}
        else r=0;
        char add[1];
        add[0]=c+'0';
        sum+=add[0];
    }
    if(r==1)sum+='1';
    sum=revers(sum);
    return sum;
}

std::string main_multi(std::string a, std::string b)
{
    std::string product="0";
    b=revers(b);
    for(unsigned long i{}; i<b.size();i++)
    {
        std::string part{};
        part=a;
        for(int j=1;j<b[i]-'0';j++)
        {
            part=main_add(a, part);
        }
        for(int j{};j<i;j++)
        {
            part+='0';
        }
        product=main_add(part, product);
    }
    return product;
}


std::string multiply(std::string a, std::string b)
{
    if(a[0]=='-'&&b[0]=='-')
    {
        a.erase(0,1);
        b.erase(0,1);
        return main_multi(a,b);
    }
    else if(a[0]=='-')
    {
        a.erase(0,1);
        return '-'+main_multi(a,b);
    }
    else if(b[0]=='-')
    {
        b.erase(0,1);
        return '-'+main_multi(a,b);
    }
    else return main_multi(a,b);
}

std::string subtraction(std::string a, std::string b)
{
    if(a[0]=='-'&&b[0]=='-')
    {
        a.erase(0,1);
        b.erase(0,1);
        bool minus=0;
        if(a.size()>b.size()) minus=1;
        else if(a.size()<b.size()) minus=0;
        else
        {
            for(unsigned long i{};i<a.size();i++)
            {
                if(a[i]>b[i]) {minus=1;break;}
                else if(a[i]<b[i]) {minus=0;break;}
                else if(i==a.size()-1) return "0";
            }
        }
        if(minus) return '-'+main_sub(a, b);
        else return main_sub(b, a);
    }
    else if(a[0]=='-')
    {
        a.erase(0,1);
        return '-'+main_add(a, b);
    }
    else if(b[0]=='-')
    {
        b.erase(0,1);
        return main_add(a, b);
    }
    else
    {
        bool minus=0;
        if(a.size()>b.size()) minus=0;
        else if(a.size()<b.size()) minus=1;
        else
        {
            for(unsigned long i{};i<a.size();i++)
            {
                if(a[i]>b[i]) {minus=0;break;}
                else if(a[i]<b[i]) {minus=1;break;}
                else if(i==a.size()-1) return "0";
            }
        }
        if(minus) return '-'+main_sub(b, a);
        else return main_sub(a, b);
    }
}

std::string addition(std::string a, std::string b)
{
    if(a[0]=='-'&&b[0]=='-')
    {
        a.erase(0,1);
        b.erase(0,1);
        return '-'+main_add(a, b);
    }
    else if(a[0]=='-')
    {
        a.erase(0,1);
        bool minus=0;
        if(a.size()>b.size()) minus=1;
        else if(a.size()<b.size()) minus=0;
        else
        {
            for(unsigned long i{};i<a.size();i++)
            {
                if(a[i]>b[i]) {minus=1;break;}
                else if(a[i]<b[i]) {minus=0;break;}
                else if(i==a.size()-1) return "0";
            }
        }
        if(minus) return '-'+main_sub(a, b);
        else return main_sub(b, a);
    }
    else if(b[0]=='-')
    {
        b.erase(0,1);
        bool minus=0;
        if(b.size()>a.size()) minus=1;
        else if(b.size()<a.size()) minus=0;
        else
        {
            for(unsigned long i{};i<b.size();i++)
            {
                if(b[i]>a[i]) {minus=1;break;}
                else if(b[i]<a[i]) {minus=0;break;}
                else if(i==b.size()-1) return "0";
            }
        }
        if(minus) return '-'+main_sub(b, a);
        else return main_sub(a, b);
    }
    else return main_add(a, b);
}

std::string main_div(std::string a, std::string b)
{
    if(a.size()<b.size()) return "0";
    if(a.size()==b.size())
    {
        for(unsigned long i{}; i<a.size();i++)
        {
            if(b[i]>a[i])return "0";
        }
    }
    std::string div{};
    unsigned long size=a.size();
    for(unsigned long i{};i<=size-b.size();i++)
    {
        std::string rest{};
        int control{};
        rest=b;
        for(unsigned long j{};j<a.size()-i-b.size();j++)
        {
            rest+="0";
        }
        bool go=0;
        a=revers(a);
        rest=revers(rest);
        for(unsigned long j=a.size(); j>=0;j++)
        {
            if(rest[j]>a[j])go=0;
            else
            {
                go=1;
                break;
            }
        }
        a=revers(a);
        rest=revers(rest);
        while(go)
        {
            a=revers(a);
            rest=revers(rest);
            if(rest[a.size()-1]>=a[a.size()-1])go=0;
            a=revers(a);
            rest=revers(rest);
            a=subtraction(a,rest);
            control++;
            std::string c;
            c=subtraction(a,rest);
            if(c[0]=='-')go=0;
        }
        char add[1];
        add[0]=control+'0';
        div+=add[0];
    }
    return div;
}

std::string division(std::string a, std::string b)
{
    if(a[0]=='-'&&b[0]=='-')
    {
        a.erase(0,1);
        b.erase(0,1);
        return main_div(a,b);
    }
    else if(a[0]=='-')
    {
        a.erase(0,1);
        return "-"+main_div(a,b);
    }
    else if(b[0]=='-')
    {
        b.erase(0,1);
        return "-"+main_div(a,b);
    }
    else return main_div(a,b);
}

void revers_test()
{
    if(revers("123")!="321")std::cout<<"Problem in revers. Expected: 321 not: "<<revers("123")<<'\n';
}

void add_test()
{
    if(addition("38", "64")!="102")std::cout<<"Problem in addition. Expected: 102 not: "<<addition("38", "64")<<'\n';
    if(addition("-38", "64")!="26")std::cout<<"Problem in addition. Expected: 26 not: "<<addition("-38", "64")<<'\n';
    if(addition("38", "-64")!="-26")std::cout<<"Problem in addition. Expected: -26 not: "<<addition("38", "-64")<<'\n';
    if(addition("-38", "-64")!="-102")std::cout<<"Problem in addition. Expected: -102 not: "<<addition("-38", "-64")<<'\n';
}

void sub_test()
{
    if(subtraction("123", "58")!="65")std::cout<<"Problem in subtraction. Expected: 65 not: "<<subtraction("123", "58")<<'\n';
    if(subtraction("-123", "58")!="-181")std::cout<<"Problem in subtraction. Expected: -181 not: "<<subtraction("-123", "58")<<'\n';
    if(subtraction("123", "-58")!="181")std::cout<<"Problem in subtraction. Expected: 181 not: "<<subtraction("123", "-58")<<'\n';
    if(subtraction("-123", "-58")!="-65")std::cout<<"Problem in subtraction. Expected: -65 not: "<<subtraction("-123", "-58")<<'\n';
}

void multi_test()
{
    if(multiply("8", "4")!="32")std::cout<<"Problem in multiply. Expected: 32 not: "<<multiply("8", "4")<<'\n';
    if(multiply("-8", "4")!="-32")std::cout<<"Problem in multiply. Expected: -32 not: "<<multiply("-8", "4")<<'\n';
    if(multiply("8", "-4")!="-32")std::cout<<"Problem in multiply. Expected: -32 not: "<<multiply("8", "-4")<<'\n';
    if(multiply("-8", "-4")!="32")std::cout<<"Problem in multiply. Expected: 32 not: "<<multiply("-8", "-4")<<'\n';
}

void div_test()
{
    if(division("234","12")!="19")std::cout<<"Problem in division. Expected: 19 not: "<<division("234","12")<<'\n';
    if(division("234","-12")!="-19")std::cout<<"Problem in division. Expected: -19 not: "<<division("234","-12")<<'\n';
    if(division("-234","12")!="-19")std::cout<<"Problem in division. Expected: -19 not: "<<division("-234","12")<<'\n';
    if(division("-234","-12")!="19")std::cout<<"Problem in division. Expected: 19 not: "<<division("-234","-12")<<'\n';
    if(division("234","12000")!="0")std::cout<<"Problem in division. Expected: 0 not: "<<division("234","12")<<'\n';
}

void test()
{
    revers_test();
    add_test();
    sub_test();
    multi_test();
    div_test();
}

void menu()
{
    std::string a{},b{};
    bool good=0;
    do
    {
        std::cout<<"Add a first number: ";
        std::cin>>a;
        if(a[0]=='-'||(a[0]>='0'&&a[0]<='9'))
        {
            for(unsigned long i=1;i<a.size();i++)
            {
                if(a[i]>='0'&&a[i]<='9') good=0;
                else
                {
                    good=1;
                    break;
                }
            }
        }
        else good=1;
    }while(good);
    do
    {
        std::cout<<"Add a secund number: ";
        std::cin>>b;
        if(b[0]=='-'||(b[0]>='0'&&b[0]<='9'))
        {
            for(unsigned long i=1;i<b.size();i++)
            {
                if(b[i]>='0'&&b[i]<='9') good=0;
                else
                {
                    good=1;
                    break;
                }
            }
        }
        else good=1;
    }while(good);
    int control;
    do
    {
        bool good;
        std::cout<<"What do you want to do?\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n\nSelect: ";
        std::cin>>control;
        if(control<1||control>4)good=1;
        else good=0;
    }while(good);
    switch(control)
    {
        case 1:
            std::cout<<addition(a,b)<<'\n';
            break;
        case 2:
            std::cout<<subtraction(a,b)<<'\n';
            break;
        case 3:
            std::cout<<multiply(a,b)<<'\n';
            break;
        case 4:
            std::cout<<division(a,b)<<'\n';
            break;
    }
}

int main()
{
    test();
    menu();
    return 0;
}
