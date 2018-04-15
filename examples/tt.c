#include <stdio.h>
#include "zlog.h"
int main(int argc, char** argv)  
{  
        printf("%s\n",argv[0]);  
    int rc;  
    zlog_category_t *zc;  
  
    rc = zlog_init("test.conf");  
    if (rc) {  
        printf("init failed\n");  
        return -1;  
    }  
  
    zc = zlog_get_category("my_cat");  
    if (!zc) {  
        printf("get cat fail\n");  
        zlog_fini();  
        return -2;  
    }  
  
    zlog_debug(zc, "%s%d","hehe",2014);  
    zlog_info(zc, "hello, zlog 2");  
  
    sleep(1);  
  
    zlog_info(zc, "hello, zlog 3");  
    zlog_debug(zc, "hello, zlog 4");  
        zlog_error(zc, "hello, zlog -- error");  
        char hehe[]="你是水阿";  
        zlog_warn(zc,hehe);  
//  zlog_profile();  
  
    zlog_fini();  
      
    return 0;  
}  