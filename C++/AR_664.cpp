#include <stdio.h>
int main() 
{    
    setbuf(stderr, NULL);
    int n, m, a;
    int ret, tmp;
    scanf("%d",&n);
    int i, j;
    while (n != 0) 
    {
        ret = 800;
        i = 0;
        while(i<n)
        {
            scanf("%d",&m);
            tmp = 0;
            j = 0;
            while(j<m)
            {
                scanf("%d",&a);
                if (tmp < a) 
                {
                    tmp = a;
                }
                ++j;
            }
            if (ret > tmp) 
            {
                ret = tmp;
            }
            ++i;
        }
        printf("%d\n",ret);
        scanf("%d",&n);
    }
    return 0;
}