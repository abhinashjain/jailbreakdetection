//
//  AnalyseFile.c
//
//  Created by abhinash jain on 22/06/16.
//  Copyright © 2016 abhinash jain. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <sys/mount.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <spawn.h>
#include <sys/uio.h>
#include <sys/syscall.h>
#include <mach-o/dyld.h>
#include <mach-o/getsect.h>
extern char **environ;


void listdir(const char *name, int level)
{
    DIR *dir;
    struct dirent *entry;
    int cnt=0;
    if(strstr(name, "NvwaStone") || strstr(name, "nvwastone") || strstr(name, "pangu") || strstr(name, "Pangu") || strstr(name, "cycript") || strstr(name, "Cycript") || strstr(name, "saurik") || strstr(name, "Cydia") || strstr(name, "cydia") || strstr(name, "Terminal") || strstr(name, "terminal"))
    {
        printf("\nContains %s: JB app might be present in the device",name );
        return;
    }

    if (!(dir = opendir(name)))
    {
//        printf("\nNumber of Files in %s: %d\n",name,cnt);
        return;
    }
    if (!(entry = readdir(dir)))
    {
//        printf("\nNumber of Files in %s: %d\n",name,cnt);
        return;
    }
    
    do {
        if (entry->d_type == DT_DIR) {
            char path[1024];
            int len = snprintf(path, sizeof(path)-1, "%s/%s", name, entry->d_name);
            path[len] = 0;
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
//            printf("%*s[%s]\n", level*2, "", entry->d_name);
            if(strstr(name, "NvwaStone") || strstr(name, "nvwastone") || strstr(name, "pangu") || strstr(name, "Pangu") || strstr(name, "cycript") || strstr(name, "Cycript") || strstr(name, "saurik"))
            {
                printf("\nContains %s: JB app might be present in the device",name);
                return;
            }
            listdir(path, level + 1);
        }
        else
        {
//            printf("%*s- %s\n", level*2, "", entry->d_name);
            if(strstr(name, "NvwaStone") || strstr(name, "nvwastone") || strstr(name, "pangu") || strstr(name, "Pangu") || strstr(name, "cycript") || strstr(name, "Cycript") || strstr(name, "saurik"))
            {
                printf("\nContains %s: JB app might be present in the device",name);
                return;
            }
        }
        cnt++;
    } while ((entry = readdir(dir)));
    closedir(dir);
//    printf("\nNumber of Files in %s: %d\n",name,cnt);
}

int analyseFile(char* name)
{
    printf("\nName: %s\n",name);

    if( access( name, F_OK ) == -1 )
    {
        printf("file not exist: No\n");
        return 0;
    }
    else
    {
        printf("file exists: Yes\n");
    }

    int fd = open(name,O_RDONLY);
    
    if(fd < 0)
    {
        printf("file can not be open: No\n");
    }
    else
    {
        printf("file can be open: Yes\n");
    }
    
    if( access( name, R_OK ) == -1 )
    {
        printf("file not readable: No\n");
    }
    else
    {
        printf("file is readable: Yes\n");
    }
    if( access( name, W_OK ) == -1 )
    {
        printf("file not writable: No\n");
    }
    else
    {
        printf("file is writeable: Yes\n");
    }
    if( access( name, X_OK ) == -1 )
    {
        printf("file not executable: No\n");
    }
    else
    {
        printf("file is executable: Yes\n");
    }
    
    struct stat st;
//    if(fstat(fd,&st)<0)
//    {
//        printf("fstat failed\n");
//    }
//    printf("%o\n",st.st_mode);

    fd=lstat(name,&st);
    printf("%o\n",st.st_mode);
    printf( (S_ISLNK(st.st_mode)) ? "l" : S_ISDIR(st.st_mode) ? "d" : "-");
    printf( (st.st_mode & S_IRUSR) ? "r" : "-");
    printf( (st.st_mode & S_IWUSR) ? "w" : "-");
    printf( (st.st_mode & S_IXUSR) ? "x" : "-");
    printf( (st.st_mode & S_IRGRP) ? "r" : "-");
    printf( (st.st_mode & S_IWGRP) ? "w" : "-");
    printf( (st.st_mode & S_IXGRP) ? "x" : "-");
    printf( (st.st_mode & S_IROTH) ? "r" : "-");
    printf( (st.st_mode & S_IWOTH) ? "w" : "-");
    printf( (st.st_mode & S_ISVTX) ? "t" : (st.st_mode & S_IXOTH) ? "x" : "-");
    printf("\nSize: %lld\n",st.st_size);

//    fd=lstat(name,&st);
//    printf("\nThe file %s a symbolic link\n\n", S_ISLNK(st.st_mode) ? "is" : "is not");
    
    close(fd);
    return 0;
}

void Jailstatfs()
{
//    FILE *fp = popen("ls", "w");
//    if(fp == NULL)
//    {
//        printf("\npopen not successful");
//    }
//    else
//    {
//        printf("\npopen successful");
//        pclose(fp);
//    }

    pid_t pid;
    char *argv[] = {"df", "", "", NULL};
    int status=posix_spawn(&pid, "/bin/df", NULL, NULL, argv, NULL);
    if(status==0)
    {
        printf("\n(JB) df: posix_spawn success: %d\n",status);
//        waitpid(pid, &status, 0);
//        if (waitpid(pid, &status, 0) != -1)
//        {
//            printf("waitpid success: %d\n", status);
//        }
//        else
//        {
//            printf("\nwaitpid error: %d",status);
//        }
    }
    else
    {
        printf("\n(Non-JB) df: posix_spawn error: %d",status);
    }

    char *argv1[] = {"ps", "", "", NULL};
    int status1=posix_spawn(&pid, "/bin/ps", NULL, NULL, argv1, NULL);
    if(status1==0)
    {
        printf("\n(JB) ps: posix_spawn success: %d\n",status1);
    }
    else
    {
        printf("\n(Non-JB) ps: posix_spawn error: %d",status1);
    }
    
    char *argv2[] = {"taskinfo", "", "", NULL};
    int status2=posix_spawn(&pid, "/usr/bin/taskinfo", NULL, NULL, argv2, NULL);
    if(status2==0)
    {
        printf("\n(JB) taskinfo: posix_spawn success: %d\n",status2);
    }
    else
    {
        printf("\n(Non-JB) taskinfo: posix_spawn error: %d",status2);
    }

    char *argv3[] = {"vm_stat", "", "", NULL};
    int status3=posix_spawn(&pid, "/usr/bin/vm_stat", NULL, NULL, argv3, NULL);
    if(status3==0)
    {
        printf("\n(JB) vm_stat: posix_spawn success: %d\n",status3);
    }
    else
    {
        printf("\n(Non-JB) vm_stat: posix_spawn error: %d",status3);
    }

    char *argv4[] = {"ipconfig", "ifcount", "", NULL};
    int status4=posix_spawn(&pid, "/usr/sbin/ipconfig", NULL, NULL, argv4, NULL);
    if(status4==0)
    {
        printf("\n(JB) ipconfig: posix_spawn success: %d\n",status4);
    }
    else
    {
        printf("\n(Non-JB) ipconfig: posix_spawn error: %d",status4);
    }
    
    char *argv5[] = {"syslogd", "", "", NULL};
    int status5=posix_spawn(&pid, "/usr/sbin/syslogd", NULL, NULL, argv5, NULL);
    if(status5==0)
    {
        printf("\n(JB) syslogd: posix_spawn success: %d\n",status5);
    }
    else
    {
        printf("\n(Non-JB) syslogd: posix_spawn error: %d",status5);
    }

    char *argv6[] = {"mDNSResponder", "", "", NULL};
    int status6=posix_spawn(&pid, "/usr/sbin/mDNSResponder", NULL, NULL, argv6, NULL);
    if(status6==0)
    {
        printf("\n(JB) mDNSResponder: posix_spawn success: %d\n",status6);
    }
    else
    {
        printf("\n(Non-JB) mDNSResponder: posix_spawn error: %d",status6);
    }

    for (int i = 0; i < _dyld_image_count(); i++)
    {
        const char *dyld = _dyld_get_image_name(i);
        if(strstr(dyld, "MobileSubstrate") || strstr(dyld, "AppList") || strstr(dyld, "CustomWidgetIcons") || strstr(dyld, "MobileSafety") || strstr(dyld, "OpenSiri") || strstr(dyld, "PreferenceLoader") || strstr(dyld, "RocketBootstrap") || strstr(dyld, "SSLKillSwitch") || strstr(dyld, "SSLKillSwitch2") || strstr(dyld, "WeeLoader") || strstr(dyld, "patcyh"))
        {
            printf("\n%s: JailBroken\n",dyld);
            break;
        }
    }

    char *env = getenv("DYLD_INSERT_LIBRARIES");
    if(env)
    {
        printf("\n%s: Jailbroken\n",env);
    }
    else
    {
        printf("\n%s: Non-JailBroken\n",env);
    }

    if(fork() >= 0)
    {
        printf("\nfork: Jailbroken");
    }
    else
    {
        printf("\nfork: Non-Jailbroken");
    }
}

