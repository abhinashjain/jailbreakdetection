//
//  checkSystemState.c
//  checkSystemState
//
//  Created by abhinash jain on 21/10/16.
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


int checkFileAccess(char* name)
{
    //NotExist
    if( access( name, F_OK ) == -1 )
    {
        if((strcmp(name, "/") == 0) || (strcmp(name, "/Applications") == 0) || (strcmp(name, "/Developer") == 0) || (strcmp(name, "/Library") == 0) || (strcmp(name, "/System") == 0) || (strcmp(name, "/bin") == 0) || (strcmp(name, "/cores") == 0) || (strcmp(name, "/dev") == 0) || (strcmp(name, "/etc") == 0) || (strcmp(name, "/private") == 0) || (strcmp(name, "/sbin") == 0) || (strcmp(name, "/tmp") == 0) || (strcmp(name, "/usr") == 0) || (strcmp(name, "/var") == 0) || (strcmp(name, "/var/mobile/Containers/Data/Application") == 0) || (strcmp(name, "/private/var/keybags") == 0) || (strcmp(name, "/Library/Keychains") == 0) || (strcmp(name, "/private/var/Keychains") == 0) || (strcmp(name, "/private/var/Keychains/keychain-2.db") == 0) || (strcmp(name, "/private/var/Keychains/TrustStore.sqlite3") == 0) || (strcmp(name, "/private/var") == 0) || (strcmp(name, "/dev/disk0s1s1") == 0) || (strcmp(name, "/dev/disk0s1s2") == 0) || (strcmp(name, "/etc/fstab") == 0) || (strcmp(name, "/usr/bin") == 0) || (strcmp(name, "/usr/sbin") == 0) || (strcmp(name, "/Library/Ringtones") == 0) || (strcmp(name, "/Library/Wallpaper") == 0) || (strcmp(name, "/usr/libexec") == 0) || (strcmp(name, "/usr/share") == 0) || (strcmp(name, "/bin/df") == 0) || (strcmp(name, "/bin/ps") == 0) || (strcmp(name, "/sbin/fsck") == 0) || (strcmp(name, "/sbin/fsck_exfat") == 0) || (strcmp(name, "/sbin/fsck_hfs") == 0) || (strcmp(name, "/sbin/fsck_msdos") == 0) || (strcmp(name, "/sbin/fstyp") == 0) || (strcmp(name, "/sbin/fstyp_hfs") == 0) || (strcmp(name, "/sbin/launchd") == 0) || (strcmp(name, "/sbin/mount") == 0) || (strcmp(name, "/sbin/mount_hfs") == 0) || (strcmp(name, "/sbin/newfs_hfs") == 0) || (strcmp(name, "/sbin/pfctl") == 0) || (strcmp(name, "/usr/bin/brctl") == 0) || (strcmp(name, "/usr/bin/powerlogHelperd") == 0) || (strcmp(name, "/usr/bin/powerlogd") == 0) || (strcmp(name, "/usr/bin/simulatecrash") == 0) || (strcmp(name, "/usr/bin/sysdiagnose") == 0) || (strcmp(name, "/usr/bin/taskinfo") == 0) || (strcmp(name, "/usr/bin/vm_stat") == 0) || (strcmp(name, "/usr/bin/zprint") == 0) || (strcmp(name, "/usr/sbin/absd") == 0) || (strcmp(name, "/usr/sbin/addNetworkInterface") == 0) || (strcmp(name, "/usr/sbin/aslmanager") == 0) || (strcmp(name, "/usr/sbin/BTAvrcp") == 0) || (strcmp(name, "/usr/sbin/BTLEServer") == 0) || (strcmp(name, "/usr/sbin/BTMap") == 0) || (strcmp(name, "/usr/sbin/BTPbap") == 0) || (strcmp(name, "/usr/sbin/BTServer") == 0) || (strcmp(name, "/usr/sbin/BlueTool") == 0) || (strcmp(name, "/usr/sbin/cfprefsd") == 0) || (strcmp(name, "/usr/sbin/distnoted") == 0) || (strcmp(name, "/usr/sbin/filecoordinationd") == 0) || (strcmp(name, "/usr/sbin/ipconfig") == 0) || (strcmp(name, "/usr/sbin/mDNSResponder") == 0) || (strcmp(name, "/usr/sbin/mDNSResponderHelper") == 0) || (strcmp(name, "/usr/sbin/mediaserverd") == 0) || (strcmp(name, "/usr/sbin/notifyd") == 0) || (strcmp(name, "/usr/sbin/nvram") == 0) || (strcmp(name, "/usr/sbin/pppd") == 0) || (strcmp(name, "/usr/sbin/racoon") == 0) || (strcmp(name, "/usr/sbin/rtadvd") == 0) || (strcmp(name, "/usr/sbin/scselect") == 0) || (strcmp(name, "/usr/sbin/scutil") == 0) || (strcmp(name, "/usr/sbin/spindump") == 0) || (strcmp(name, "/usr/sbin/syslogd") == 0) || (strcmp(name, "/usr/sbin/wifid") == 0) || (strcmp(name, "/usr/sbin/wirelessproxd") == 0) || (strcmp(name, "/usr/sbin/WirelessRadioManagerd") == 0) || (strcmp(name, "/usr/libexec/BackupAgent") == 0) || (strcmp(name, "/usr/libexec/BackupAgent2") == 0) || (strcmp(name, "/usr/libexec/CrashHousekeeping") == 0) || (strcmp(name, "/usr/libexec/DuetHeuristic-BM") == 0) || (strcmp(name, "/usr/libexec/FSTaskScheduler") == 0) || (strcmp(name, "/usr/libexec/FinishRestoreFromBackup") == 0) || (strcmp(name, "/usr/libexec/MobileGestaltHelper") == 0) || (strcmp(name, "/usr/libexec/NANDTaskScheduler") == 0) || (strcmp(name, "/usr/libexec/OTAPKIAssetTool") == 0) || (strcmp(name, "/usr/libexec/OTATaskingAgent") == 0) || (strcmp(name, "/usr/libexec/PreboardService") == 0) || (strcmp(name, "/usr/libexec/ProxiedCrashCopier") == 0) || (strcmp(name, "/usr/libexec/PurpleReverseProxy") == 0) || (strcmp(name, "/usr/libexec/SafariCloudHistoryPushAgent") == 0) || (strcmp(name, "/usr/libexec/SyncAgent") == 0) || (strcmp(name, "/usr/libexec/UserEventAgent") == 0) || (strcmp(name, "/usr/libexec/adid") == 0) || (strcmp(name, "/usr/libexec/afcd") == 0) || (strcmp(name, "/usr/libexec/aitd") == 0) || (strcmp(name, "/usr/libexec/amfid") == 0) || (strcmp(name, "/usr/libexec/assertiond") == 0) || (strcmp(name, "/usr/libexec/atc") == 0) || (strcmp(name, "/usr/libexec/atwakeup") == 0) || (strcmp(name, "/usr/libexec/backboardd") == 0) || (strcmp(name, "/usr/libexec/biometrickitd") == 0) || (strcmp(name, "/usr/libexec/bootpd") == 0) || (strcmp(name, "/usr/libexec/cc_fips_test") == 0) || (strcmp(name, "/usr/libexec/checkpointd") == 0) || (strcmp(name, "/usr/libexec/companion_proxy") == 0) || (strcmp(name, "/usr/libexec/configd") == 0) || (strcmp(name, "/usr/libexec/corecaptured") == 0) || (strcmp(name, "/usr/libexec/coreduetd") == 0) || (strcmp(name, "/usr/libexec/crash_mover") == 0) || (strcmp(name, "/usr/libexec/demod") == 0) || (strcmp(name, "/usr/libexec/demod_helper") == 0) || (strcmp(name, "/usr/libexec/dhcpd") == 0) || (strcmp(name, "/usr/libexec/diagnosticd") == 0) || (strcmp(name, "/usr/libexec/duetexpertd") == 0) || (strcmp(name, "/usr/libexec/findmydeviced") == 0) || (strcmp(name, "/usr/libexec/fmfd") == 0) || (strcmp(name, "/usr/libexec/fseventsd") == 0) || (strcmp(name, "/usr/libexec/ftp-proxy") == 0) || (strcmp(name, "/usr/libexec/gamecontrollerd") == 0) || (strcmp(name, "/usr/libexec/gamed") == 0) || (strcmp(name, "/usr/libexec/hangtracerd") == 0) || (strcmp(name, "/usr/libexec/hostapd") == 0) || (strcmp(name, "/usr/libexec/idamd") == 0) || (strcmp(name, "/usr/libexec/init_data_protection") == 0) || (strcmp(name, "/usr/libexec/installd") == 0) || (strcmp(name, "/usr/libexec/ioupsd") == 0) || (strcmp(name, "/usr/libexec/keybagd") == 0) || (strcmp(name, "/usr/libexec/languageassetd") == 0) || (strcmp(name, "/usr/libexec/limitadtrackingd") == 0) || (strcmp(name, "/usr/libexec/locationd") == 0) || (strcmp(name, "/usr/libexec/lockbot") == 0) || (strcmp(name, "/usr/libexec/lockdownd") == 0) || (strcmp(name, "/usr/libexec/logd") == 0) || (strcmp(name, "/usr/libexec/lsd") == 0) || (strcmp(name, "/usr/libexec/lskdd") == 0) || (strcmp(name, "/usr/libexec/lskdmsed") == 0) || (strcmp(name, "/usr/libexec/mc_mobile_tunnel") == 0) || (strcmp(name, "/usr/libexec/misagent") == 0) || (strcmp(name, "/usr/libexec/misd") == 0) || (strcmp(name, "/usr/libexec/mmaintenanced") == 0) || (strcmp(name, "/usr/libexec/mobile_assertion_agent") == 0) || (strcmp(name, "/usr/libexec/mobile_diagnostics_relay") == 0) || (strcmp(name, "/usr/libexec/mobile_file_relay") == 0) || (strcmp(name, "/usr/libexec/mobile_house_arrest") == 0) || (strcmp(name, "/usr/libexec/mobile_installation_proxy") == 0) || (strcmp(name, "/usr/libexec/mobile_obliterator") == 0) || (strcmp(name, "/usr/libexec/mobile_storage_proxy") == 0) || (strcmp(name, "/usr/libexec/mobileassetd") == 0) || (strcmp(name, "/usr/libexec/mtmergeprops") == 0) || (strcmp(name, "/usr/libexec/neagent") == 0) || (strcmp(name, "/usr/libexec/nehelper") == 0) || (strcmp(name, "/usr/libexec/nesessionmanager") == 0) || (strcmp(name, "/usr/libexec/nfcd") == 0) || (strcmp(name, "/usr/libexec/nlcd") == 0) || (strcmp(name, "/usr/libexec/notification_proxy") == 0) || (strcmp(name, "/usr/libexec/nsurlsessiond") == 0) || (strcmp(name, "/usr/libexec/nsurlstoraged") == 0) || (strcmp(name, "/usr/libexec/online-auth-agent") == 0) || (strcmp(name, "/usr/libexec/oscard") == 0) || (strcmp(name, "/usr/libexec/pcapd") == 0) || (strcmp(name, "/usr/libexec/pfd") == 0) || (strcmp(name, "/usr/libexec/pipelined") == 0) || (strcmp(name, "/usr/libexec/pkd") == 0) || (strcmp(name, "/usr/libexec/pkreporter") == 0) || (strcmp(name, "/usr/libexec/ptpd") == 0) || (strcmp(name, "/usr/libexec/replayd") == 0) || (strcmp(name, "/usr/libexec/rolld") == 0) || (strcmp(name, "/usr/libexec/routined") == 0) || (strcmp(name, "/usr/libexec/rtcreportingd") == 0) || (strcmp(name, "/usr/libexec/securityd") == 0) || (strcmp(name, "/usr/libexec/seld") == 0) || (strcmp(name, "/usr/libexec/seputil") == 0) || (strcmp(name, "/usr/libexec/sharingd") == 0) || (strcmp(name, "/usr/libexec/splashboardd") == 0) || (strcmp(name, "/usr/libexec/springboardservicesrelay") == 0) || (strcmp(name, "/usr/libexec/streaming_zip_conduit") == 0) || (strcmp(name, "/usr/libexec/swcd") == 0) || (strcmp(name, "/usr/libexec/symptomsd") == 0) || (strcmp(name, "/usr/libexec/symptomsd-helper") == 0) || (strcmp(name, "/usr/libexec/syslog_relay") == 0) || (strcmp(name, "/usr/libexec/sysstatuscheck") == 0) || (strcmp(name, "/usr/libexec/timed") == 0) || (strcmp(name, "/usr/libexec/tipsd") == 0) || (strcmp(name, "/usr/libexec/transitd") == 0) || (strcmp(name, "/usr/libexec/tzd") == 0) || (strcmp(name, "/usr/libexec/tzinit") == 0) || (strcmp(name, "/usr/libexec/tzlinkd") == 0) || (strcmp(name, "/usr/libexec/wapic") == 0) || (strcmp(name, "/usr/libexec/webinspectord") == 0) || (strcmp(name, "/usr/libexec/wifiFirmwareLoader") == 0) || (strcmp(name, "/usr/libexec/xpcproxy") == 0) || (strcmp(name, "/usr/lib") == 0) || (strcmp(name, "/Library/LaunchAgents") == 0) || (strcmp(name, "/System/Library/LaunchDaemons") == 0) || (strcmp(name, "/private/var/root") == 0) || (strcmp(name, "/private/var/mobile") == 0) || (strcmp(name, "/private/var/mobile/Library") == 0) || (strcmp(name, "/private/var/mobile/Library/Caches") == 0) /*need more testing*/ || (strcmp(name, "/dev/tty.iap") == 0) /*need more testing*/)
        {
            return 1;
        }
        
        
        // /var/mobile/Containers/Bundle/Application specific for 9.21
        // /var/containers/Bundle/Application, /dev/disk4, /usr/libexec/bubbled, /usr/libexec/hangreporter, /usr/libexec/ifccd, /usr/libexec/mailq, /usr/libexec/mobileactivationd for 9.33 and 10.02
        // /usr/libexec/aosnotifyd, /usr/libexec/findmydeviced-nano-support, /usr/libexec/ios_diagnostics_relay, /usr/libexec/networkd, /usr/libexec/networkd_privileged, /usr/libexec/uuidpathd for 9.21 and 9.33
        return 0;
    }
    
    int fd = open(name,O_RDONLY);

    //Openable
    if(fd >= 0)
    {
        if((strcmp(name, "/Library") == 0) || (strcmp(name, "/System") == 0) || (strcmp(name, "/bin") == 0) || (strcmp(name, "/cores") == 0) || (strcmp(name, "/dev") == 0) || (strcmp(name, "/etc") == 0) || (strcmp(name, "/private") == 0) || (strcmp(name, "/sbin") == 0) || (strcmp(name, "/tmp") == 0) || (strcmp(name, "/usr") == 0) || (strcmp(name, "/var") == 0) || (strcmp(name, "/var/mobile/Containers/Data/Application") == 0) || (strcmp(name, "/var/mobile/Containers/Bundle/Application") == 0) || (strcmp(name, "/var/containers/Bundle/Application") == 0) || (strcmp(name, "/Library/Keychains") == 0) || (strcmp(name, "/private/var/Keychains") == 0) || (strcmp(name, "/private/var") == 0) || (strcmp(name, "/etc/fstab") == 0) || (strcmp(name, "/usr/bin") == 0) || (strcmp(name, "/usr/sbin") == 0) || (strcmp(name, "/Library/Wallpaper") == 0) || (strcmp(name, "/usr/libexec") == 0) || (strcmp(name, "/bin/df") == 0) || (strcmp(name, "/bin/ps") == 0) || (strcmp(name, "/sbin/fsck") == 0) || (strcmp(name, "/sbin/fstyp") == 0) || (strcmp(name, "/sbin/fstyp_hfs") == 0) || (strcmp(name, "/sbin/launchd") == 0) || (strcmp(name, "/sbin/mount") == 0) || (strcmp(name, "/sbin/pfctl") == 0) || (strcmp(name, "/usr/bin/brctl") == 0) || (strcmp(name, "/usr/bin/powerlogHelperd") == 0) || (strcmp(name, "/usr/bin/powerlogd") == 0) || (strcmp(name, "/usr/bin/simulatecrash") == 0) || (strcmp(name, "/usr/bin/sysdiagnose") == 0) || (strcmp(name, "/usr/bin/taskinfo") == 0) || (strcmp(name, "/usr/bin/vm_stat") == 0) || (strcmp(name, "/usr/bin/zprint") == 0) || (strcmp(name, "/usr/sbin/absd") == 0) || (strcmp(name, "/usr/sbin/addNetworkInterface") == 0) || (strcmp(name, "/usr/sbin/aslmanager") == 0) || (strcmp(name, "/usr/sbin/BTAvrcp") == 0) || (strcmp(name, "/usr/sbin/BTLEServer") == 0) || (strcmp(name, "/usr/sbin/BTMap") == 0) || (strcmp(name, "/usr/sbin/BTPbap") == 0) || (strcmp(name, "/usr/sbin/BTServer") == 0) || (strcmp(name, "/usr/sbin/BlueTool") == 0) || (strcmp(name, "/usr/sbin/cfprefsd") == 0) || (strcmp(name, "/usr/sbin/distnoted") == 0) || (strcmp(name, "/usr/sbin/filecoordinationd") == 0) || (strcmp(name, "/usr/sbin/ipconfig") == 0) || (strcmp(name, "/usr/sbin/mDNSResponder") == 0) || (strcmp(name, "/usr/sbin/mDNSResponderHelper") == 0) || (strcmp(name, "/usr/sbin/mediaserverd") == 0) || (strcmp(name, "/usr/sbin/notifyd") == 0) || (strcmp(name, "/usr/sbin/nvram") == 0) || (strcmp(name, "/usr/sbin/pppd") == 0) || (strcmp(name, "/usr/sbin/racoon") == 0) || (strcmp(name, "/usr/sbin/rtadvd") == 0) || (strcmp(name, "/usr/sbin/scselect") == 0) || (strcmp(name, "/usr/sbin/scutil") == 0) || (strcmp(name, "/usr/sbin/spindump") == 0) || (strcmp(name, "/usr/sbin/syslogd") == 0) || (strcmp(name, "/usr/sbin/wifid") == 0) || (strcmp(name, "/usr/sbin/wirelessproxd") == 0) || (strcmp(name, "/usr/sbin/WirelessRadioManagerd") == 0) || (strcmp(name, "/usr/libexec/BackupAgent") == 0) || (strcmp(name, "/usr/libexec/BackupAgent2") == 0) || (strcmp(name, "/usr/libexec/CrashHousekeeping") == 0) || (strcmp(name, "/usr/libexec/DuetHeuristic-BM") == 0) || (strcmp(name, "/usr/libexec/FSTaskScheduler") == 0) || (strcmp(name, "/usr/libexec/FinishRestoreFromBackup") == 0) || (strcmp(name, "/usr/libexec/MobileGestaltHelper") == 0) || (strcmp(name, "/usr/libexec/NANDTaskScheduler") == 0) || (strcmp(name, "/usr/libexec/OTAPKIAssetTool") == 0) || (strcmp(name, "/usr/libexec/OTATaskingAgent") == 0) || (strcmp(name, "/usr/libexec/PreboardService") == 0) || (strcmp(name, "/usr/libexec/ProxiedCrashCopier") == 0) || (strcmp(name, "/usr/libexec/PurpleReverseProxy") == 0) || (strcmp(name, "/usr/libexec/SafariCloudHistoryPushAgent") == 0) || (strcmp(name, "/usr/libexec/SyncAgent") == 0) || (strcmp(name, "/usr/libexec/UserEventAgent") == 0) || (strcmp(name, "/usr/libexec/adid") == 0) || (strcmp(name, "/usr/libexec/afcd") == 0) || (strcmp(name, "/usr/libexec/aitd") == 0) || (strcmp(name, "/usr/libexec/amfid") == 0) || (strcmp(name, "/usr/libexec/assertiond") == 0) || (strcmp(name, "/usr/libexec/atc") == 0) || (strcmp(name, "/usr/libexec/atwakeup") == 0) || (strcmp(name, "/usr/libexec/backboardd") == 0) || (strcmp(name, "/usr/libexec/biometrickitd") == 0) || (strcmp(name, "/usr/libexec/bootpd") == 0)|| (strcmp(name, "/usr/libexec/bubbled") == 0) || (strcmp(name, "/usr/libexec/cc_fips_test") == 0) || (strcmp(name, "/usr/libexec/checkpointd") == 0) || (strcmp(name, "/usr/libexec/companion_proxy") == 0) || (strcmp(name, "/usr/libexec/configd") == 0) || (strcmp(name, "/usr/libexec/corecaptured") == 0) || (strcmp(name, "/usr/libexec/coreduetd") == 0) || (strcmp(name, "/usr/libexec/crash_mover") == 0) || (strcmp(name, "/usr/libexec/demod") == 0) || (strcmp(name, "/usr/libexec/demod_helper") == 0) || (strcmp(name, "/usr/libexec/dhcpd") == 0) || (strcmp(name, "/usr/libexec/diagnosticd") == 0) || (strcmp(name, "/usr/libexec/duetexpertd") == 0) || (strcmp(name, "/usr/libexec/findmydeviced") == 0) || (strcmp(name, "/usr/libexec/fmfd") == 0) || (strcmp(name, "/usr/libexec/fseventsd") == 0) || (strcmp(name, "/usr/libexec/ftp-proxy") == 0) || (strcmp(name, "/usr/libexec/gamecontrollerd") == 0) || (strcmp(name, "/usr/libexec/gamed") == 0) || (strcmp(name, "/usr/libexec/hangreporter") == 0) || (strcmp(name, "/usr/libexec/hangtracerd") == 0) || (strcmp(name, "/usr/libexec/hostapd") == 0) || (strcmp(name, "/usr/libexec/idamd") == 0) || (strcmp(name, "/usr/libexec/ifccd") == 0) || (strcmp(name, "/usr/libexec/init_data_protection") == 0) || (strcmp(name, "/usr/libexec/installd") == 0) || (strcmp(name, "/usr/libexec/ioupsd") == 0) || (strcmp(name, "/usr/libexec/keybagd") == 0) || (strcmp(name, "/usr/libexec/languageassetd") == 0) || (strcmp(name, "/usr/libexec/limitadtrackingd") == 0) || (strcmp(name, "/usr/libexec/locationd") == 0) || (strcmp(name, "/usr/libexec/lockbot") == 0) || (strcmp(name, "/usr/libexec/lockdownd") == 0) || (strcmp(name, "/usr/libexec/logd") == 0) || (strcmp(name, "/usr/libexec/lsd") == 0) || (strcmp(name, "/usr/libexec/lskdd") == 0) || (strcmp(name, "/usr/libexec/lskdmsed") == 0) || (strcmp(name, "/usr/libexec/mailq") == 0) || (strcmp(name, "/usr/libexec/mc_mobile_tunnel") == 0) || (strcmp(name, "/usr/libexec/misagent") == 0) || (strcmp(name, "/usr/libexec/misd") == 0) || (strcmp(name, "/usr/libexec/mmaintenanced") == 0) || (strcmp(name, "/usr/libexec/mobile_assertion_agent") == 0) || (strcmp(name, "/usr/libexec/mobile_diagnostics_relay") == 0) || (strcmp(name, "/usr/libexec/mobile_ le_relay") == 0) || (strcmp(name, "/usr/libexec/mobile_house_arrest") == 0) || (strcmp(name, "/usr/libexec/mobile_installation_proxy") == 0) || (strcmp(name, "/usr/libexec/mobile_obliterator") == 0) || (strcmp(name, "/usr/libexec/mobile_storage_proxy") == 0) || (strcmp(name, "/usr/libexec/mobileactivationd") == 0) || (strcmp(name, "/usr/libexec/mobileassetd") == 0) || (strcmp(name, "/usr/libexec/mtmergeprops") == 0) || (strcmp(name, "/usr/libexec/neagent") == 0) || (strcmp(name, "/usr/libexec/nehelper") == 0) || (strcmp(name, "/usr/libexec/nesessionmanager") == 0) || (strcmp(name, "/usr/libexec/nfcd") == 0) || (strcmp(name, "/usr/libexec/nlcd") == 0) || (strcmp(name, "/usr/libexec/notification_proxy") == 0) || (strcmp(name, "/usr/libexec/nsurlsessiond") == 0) || (strcmp(name, "/usr/libexec/nsurlstoraged") == 0) || (strcmp(name, "/usr/libexec/online-auth-agent") == 0) || (strcmp(name, "/usr/libexec/oscard") == 0) || (strcmp(name, "/usr/libexec/pcapd") == 0) || (strcmp(name, "/usr/libexec/pfd") == 0) || (strcmp(name, "/usr/libexec/pipelined") == 0) || (strcmp(name, "/usr/libexec/pkd") == 0) || (strcmp(name, "/usr/libexec/pkreporter") == 0) || (strcmp(name, "/usr/libexec/ptpd") == 0) || (strcmp(name, "/usr/libexec/replayd") == 0) || (strcmp(name, "/usr/libexec/rolld") == 0) || (strcmp(name, "/usr/libexec/routined") == 0) || (strcmp(name, "/usr/libexec/rtcreportingd") == 0) || (strcmp(name, "/usr/libexec/securityd") == 0) || (strcmp(name, "/usr/libexec/seld") == 0) || (strcmp(name, "/usr/libexec/seputil") == 0) || (strcmp(name, "/usr/libexec/sharingd") == 0) || (strcmp(name, "/usr/libexec/splashboardd") == 0) || (strcmp(name, "/usr/libexec/springboardservicesrelay") == 0) || (strcmp(name, "/usr/libexec/streaming_zip_conduit") == 0) || (strcmp(name, "/usr/libexec/swcd") == 0) || (strcmp(name, "/usr/libexec/symptomsd") == 0) || (strcmp(name, "/usr/libexec/symptomsd-helper") == 0) || (strcmp(name, "/usr/libexec/syslog_relay") == 0) || (strcmp(name, "/usr/libexec/sysstatuscheck") == 0) || (strcmp(name, "/usr/libexec/timed") == 0) || (strcmp(name, "/usr/libexec/tipsd") == 0) || (strcmp(name, "/usr/libexec/transitd") == 0) || (strcmp(name, "/usr/libexec/tzd") == 0) || (strcmp(name, "/usr/libexec/tzinit") == 0) || (strcmp(name, "/usr/libexec/tzlinkd") == 0) || (strcmp(name, "/usr/libexec/wapic") == 0) || (strcmp(name, "/usr/libexec/webinspectord") == 0) || (strcmp(name, "/usr/libexec/wifiFirmwareLoader") == 0) || (strcmp(name, "/usr/libexec/xpcproxy") == 0) || (strcmp(name, "/Library/LaunchAgents") == 0) || (strcmp(name, "/usr/libexec/aosnotifyd") == 0) || (strcmp(name, "/usr/libexec/findmydeviced-nano-support") == 0) || (strcmp(name, "/usr/libexec/ios_diagnostics_relay") == 0) || (strcmp(name, "/usr/libexec/networkd") == 0) || (strcmp(name, "/usr/libexec/networkd_privileged") == 0) || (strcmp(name, "/usr/libexec/uuidpathd") == 0) || (strcmp(name, "/private/var/root") == 0) || (strcmp(name, "/private/var/mobile") == 0) || (strcmp(name, "/private/var/mobile/Library") == 0) || (strcmp(name, "/private/var/mobile/Library/Caches") == 0) || (strcmp(name, "/private/var/keybags") == 0) || (strcmp(name, "/private/var/Keychains/keychain-2.db") == 0) || (strcmp(name, "/private/var/Keychains/TrustStore.sqlite3") == 0) || (strcmp(name, "/dev/disk0s1s1") == 0) || (strcmp(name, "/dev/disk0s1s2") == 0) || (strcmp(name, "/dev/disk4") == 0) /*need more testing*/ || (strcmp(name, "/dev/tty.iap") == 0) /*need more testing*/)
        {
            close(fd);
            return 1;
        }
    }
    //NotOpenable
    else
    {
        if((strcmp(name, "/") == 0) || (strcmp(name, "/Developer") == 0) || (strcmp(name, "/Library/Ringtones") == 0) || (strcmp(name, "/usr/share") == 0) || (strcmp(name, "/sbin/fsck_exfat") == 0) || (strcmp(name, "/sbin/fsck_hfs") == 0) || (strcmp(name, "/sbin/fsck_msdos") == 0) || (strcmp(name, "/sbin/mount_hfs") == 0) || (strcmp(name, "/sbin/newfs_hfs") == 0) || (strcmp(name, "/usr/lib") == 0) || (strcmp(name, "/System/Library/LaunchDaemons") == 0))
        {
            close(fd);
            return 1;
        }
        // /Applications different for versions
    }
    close(fd);

    //Readable
    if( access( name, R_OK ) != -1 )
    {
        if((strcmp(name, "/Library") == 0) || (strcmp(name, "/System") == 0) || (strcmp(name, "/bin") == 0) || (strcmp(name, "/cores") == 0) || (strcmp(name, "/dev") == 0) || (strcmp(name, "/etc") == 0) || (strcmp(name, "/private") == 0) || (strcmp(name, "/sbin") == 0) || (strcmp(name, "/tmp") == 0) || (strcmp(name, "/usr") == 0) || (strcmp(name, "/var") == 0) || (strcmp(name, "/var/mobile/Containers/Data/Application") == 0) || (strcmp(name, "/var/mobile/Containers/Bundle/Application") == 0) || (strcmp(name, "/var/containers/Bundle/Application") == 0) || (strcmp(name, "/Library/Keychains") == 0) || (strcmp(name, "/private/var/Keychains") == 0) || (strcmp(name, "/private/var") == 0) || (strcmp(name, "/etc/fstab") == 0) || (strcmp(name, "/usr/bin") == 0) || (strcmp(name, "/usr/sbin") == 0) || (strcmp(name, "/Library/Wallpaper") == 0) || (strcmp(name, "/usr/libexec") == 0) || (strcmp(name, "/bin/df") == 0) || (strcmp(name, "/bin/ps") == 0) || (strcmp(name, "/sbin/fsck") == 0) || (strcmp(name, "/sbin/fstyp") == 0) || (strcmp(name, "/sbin/fstyp_hfs") == 0) || (strcmp(name, "/sbin/launchd") == 0) || (strcmp(name, "/sbin/mount") == 0) || (strcmp(name, "/sbin/pfctl") == 0) || (strcmp(name, "/usr/bin/brctl") == 0) || (strcmp(name, "/usr/bin/powerlogHelperd") == 0) || (strcmp(name, "/usr/bin/powerlogd") == 0) || (strcmp(name, "/usr/bin/simulatecrash") == 0) || (strcmp(name, "/usr/bin/sysdiagnose") == 0) || (strcmp(name, "/usr/bin/taskinfo") == 0) || (strcmp(name, "/usr/bin/vm_stat") == 0) || (strcmp(name, "/usr/bin/zprint") == 0) || (strcmp(name, "/usr/sbin/absd") == 0) || (strcmp(name, "/usr/sbin/addNetworkInterface") == 0) || (strcmp(name, "/usr/sbin/aslmanager") == 0) || (strcmp(name, "/usr/sbin/BTAvrcp") == 0) || (strcmp(name, "/usr/sbin/BTLEServer") == 0) || (strcmp(name, "/usr/sbin/BTMap") == 0) || (strcmp(name, "/usr/sbin/BTPbap") == 0) || (strcmp(name, "/usr/sbin/BTServer") == 0) || (strcmp(name, "/usr/sbin/BlueTool") == 0) || (strcmp(name, "/usr/sbin/cfprefsd") == 0) || (strcmp(name, "/usr/sbin/distnoted") == 0) || (strcmp(name, "/usr/sbin/filecoordinationd") == 0) || (strcmp(name, "/usr/sbin/ipconfig") == 0) || (strcmp(name, "/usr/sbin/mDNSResponder") == 0) || (strcmp(name, "/usr/sbin/mDNSResponderHelper") == 0) || (strcmp(name, "/usr/sbin/mediaserverd") == 0) || (strcmp(name, "/usr/sbin/notifyd") == 0) || (strcmp(name, "/usr/sbin/nvram") == 0) || (strcmp(name, "/usr/sbin/pppd") == 0) || (strcmp(name, "/usr/sbin/racoon") == 0) || (strcmp(name, "/usr/sbin/rtadvd") == 0) || (strcmp(name, "/usr/sbin/scselect") == 0) || (strcmp(name, "/usr/sbin/scutil") == 0) || (strcmp(name, "/usr/sbin/spindump") == 0) || (strcmp(name, "/usr/sbin/syslogd") == 0) || (strcmp(name, "/usr/sbin/wifid") == 0) || (strcmp(name, "/usr/sbin/wirelessproxd") == 0) || (strcmp(name, "/usr/sbin/WirelessRadioManagerd") == 0) || (strcmp(name, "/usr/libexec/BackupAgent") == 0) || (strcmp(name, "/usr/libexec/BackupAgent2") == 0) || (strcmp(name, "/usr/libexec/CrashHousekeeping") == 0) || (strcmp(name, "/usr/libexec/DuetHeuristic-BM") == 0) || (strcmp(name, "/usr/libexec/FSTaskScheduler") == 0) || (strcmp(name, "/usr/libexec/FinishRestoreFromBackup") == 0) || (strcmp(name, "/usr/libexec/MobileGestaltHelper") == 0) || (strcmp(name, "/usr/libexec/NANDTaskScheduler") == 0) || (strcmp(name, "/usr/libexec/OTAPKIAssetTool") == 0) || (strcmp(name, "/usr/libexec/OTATaskingAgent") == 0) || (strcmp(name, "/usr/libexec/PreboardService") == 0) || (strcmp(name, "/usr/libexec/ProxiedCrashCopier") == 0) || (strcmp(name, "/usr/libexec/PurpleReverseProxy") == 0) || (strcmp(name, "/usr/libexec/SafariCloudHistoryPushAgent") == 0) || (strcmp(name, "/usr/libexec/SyncAgent") == 0) || (strcmp(name, "/usr/libexec/UserEventAgent") == 0) || (strcmp(name, "/usr/libexec/adid") == 0) || (strcmp(name, "/usr/libexec/afcd") == 0) || (strcmp(name, "/usr/libexec/aitd") == 0) || (strcmp(name, "/usr/libexec/amfid") == 0) || (strcmp(name, "/usr/libexec/assertiond") == 0) || (strcmp(name, "/usr/libexec/atc") == 0) || (strcmp(name, "/usr/libexec/atwakeup") == 0) || (strcmp(name, "/usr/libexec/backboardd") == 0) || (strcmp(name, "/usr/libexec/biometrickitd") == 0) || (strcmp(name, "/usr/libexec/bootpd") == 0)|| (strcmp(name, "/usr/libexec/bubbled") == 0) || (strcmp(name, "/usr/libexec/cc_fips_test") == 0) || (strcmp(name, "/usr/libexec/checkpointd") == 0) || (strcmp(name, "/usr/libexec/companion_proxy") == 0) || (strcmp(name, "/usr/libexec/configd") == 0) || (strcmp(name, "/usr/libexec/corecaptured") == 0) || (strcmp(name, "/usr/libexec/coreduetd") == 0) || (strcmp(name, "/usr/libexec/crash_mover") == 0) || (strcmp(name, "/usr/libexec/demod") == 0) || (strcmp(name, "/usr/libexec/demod_helper") == 0) || (strcmp(name, "/usr/libexec/dhcpd") == 0) || (strcmp(name, "/usr/libexec/diagnosticd") == 0) || (strcmp(name, "/usr/libexec/duetexpertd") == 0) || (strcmp(name, "/usr/libexec/findmydeviced") == 0) || (strcmp(name, "/usr/libexec/fmfd") == 0) || (strcmp(name, "/usr/libexec/fseventsd") == 0) || (strcmp(name, "/usr/libexec/ftp-proxy") == 0) || (strcmp(name, "/usr/libexec/gamecontrollerd") == 0) || (strcmp(name, "/usr/libexec/gamed") == 0) || (strcmp(name, "/usr/libexec/hangreporter") == 0) || (strcmp(name, "/usr/libexec/hangtracerd") == 0) || (strcmp(name, "/usr/libexec/hostapd") == 0) || (strcmp(name, "/usr/libexec/idamd") == 0) || (strcmp(name, "/usr/libexec/ifccd") == 0) || (strcmp(name, "/usr/libexec/init_data_protection") == 0) || (strcmp(name, "/usr/libexec/installd") == 0) || (strcmp(name, "/usr/libexec/ioupsd") == 0) || (strcmp(name, "/usr/libexec/keybagd") == 0) || (strcmp(name, "/usr/libexec/languageassetd") == 0) || (strcmp(name, "/usr/libexec/limitadtrackingd") == 0) || (strcmp(name, "/usr/libexec/locationd") == 0) || (strcmp(name, "/usr/libexec/lockbot") == 0) || (strcmp(name, "/usr/libexec/lockdownd") == 0) || (strcmp(name, "/usr/libexec/logd") == 0) || (strcmp(name, "/usr/libexec/lsd") == 0) || (strcmp(name, "/usr/libexec/lskdd") == 0) || (strcmp(name, "/usr/libexec/lskdmsed") == 0) || (strcmp(name, "/usr/libexec/mailq") == 0) || (strcmp(name, "/usr/libexec/mc_mobile_tunnel") == 0) || (strcmp(name, "/usr/libexec/misagent") == 0) || (strcmp(name, "/usr/libexec/misd") == 0) || (strcmp(name, "/usr/libexec/mmaintenanced") == 0) || (strcmp(name, "/usr/libexec/mobile_assertion_agent") == 0) || (strcmp(name, "/usr/libexec/mobile_diagnostics_relay") == 0) || (strcmp(name, "/usr/libexec/mobile_ le_relay") == 0) || (strcmp(name, "/usr/libexec/mobile_house_arrest") == 0) || (strcmp(name, "/usr/libexec/mobile_installation_proxy") == 0) || (strcmp(name, "/usr/libexec/mobile_obliterator") == 0) || (strcmp(name, "/usr/libexec/mobile_storage_proxy") == 0) || (strcmp(name, "/usr/libexec/mobileactivationd") == 0) || (strcmp(name, "/usr/libexec/mobileassetd") == 0) || (strcmp(name, "/usr/libexec/mtmergeprops") == 0) || (strcmp(name, "/usr/libexec/neagent") == 0) || (strcmp(name, "/usr/libexec/nehelper") == 0) || (strcmp(name, "/usr/libexec/nesessionmanager") == 0) || (strcmp(name, "/usr/libexec/nfcd") == 0) || (strcmp(name, "/usr/libexec/nlcd") == 0) || (strcmp(name, "/usr/libexec/notification_proxy") == 0) || (strcmp(name, "/usr/libexec/nsurlsessiond") == 0) || (strcmp(name, "/usr/libexec/nsurlstoraged") == 0) || (strcmp(name, "/usr/libexec/online-auth-agent") == 0) || (strcmp(name, "/usr/libexec/oscard") == 0) || (strcmp(name, "/usr/libexec/pcapd") == 0) || (strcmp(name, "/usr/libexec/pfd") == 0) || (strcmp(name, "/usr/libexec/pipelined") == 0) || (strcmp(name, "/usr/libexec/pkd") == 0) || (strcmp(name, "/usr/libexec/pkreporter") == 0) || (strcmp(name, "/usr/libexec/ptpd") == 0) || (strcmp(name, "/usr/libexec/replayd") == 0) || (strcmp(name, "/usr/libexec/rolld") == 0) || (strcmp(name, "/usr/libexec/routined") == 0) || (strcmp(name, "/usr/libexec/rtcreportingd") == 0) || (strcmp(name, "/usr/libexec/securityd") == 0) || (strcmp(name, "/usr/libexec/seld") == 0) || (strcmp(name, "/usr/libexec/seputil") == 0) || (strcmp(name, "/usr/libexec/sharingd") == 0) || (strcmp(name, "/usr/libexec/splashboardd") == 0) || (strcmp(name, "/usr/libexec/springboardservicesrelay") == 0) || (strcmp(name, "/usr/libexec/streaming_zip_conduit") == 0) || (strcmp(name, "/usr/libexec/swcd") == 0) || (strcmp(name, "/usr/libexec/symptomsd") == 0) || (strcmp(name, "/usr/libexec/symptomsd-helper") == 0) || (strcmp(name, "/usr/libexec/syslog_relay") == 0) || (strcmp(name, "/usr/libexec/sysstatuscheck") == 0) || (strcmp(name, "/usr/libexec/timed") == 0) || (strcmp(name, "/usr/libexec/tipsd") == 0) || (strcmp(name, "/usr/libexec/transitd") == 0) || (strcmp(name, "/usr/libexec/tzd") == 0) || (strcmp(name, "/usr/libexec/tzinit") == 0) || (strcmp(name, "/usr/libexec/tzlinkd") == 0) || (strcmp(name, "/usr/libexec/wapic") == 0) || (strcmp(name, "/usr/libexec/webinspectord") == 0) || (strcmp(name, "/usr/libexec/wifiFirmwareLoader") == 0) || (strcmp(name, "/usr/libexec/xpcproxy") == 0) || (strcmp(name, "/Library/LaunchAgents") == 0) || (strcmp(name, "/usr/libexec/aosnotifyd") == 0) || (strcmp(name, "/usr/libexec/findmydeviced-nano-support") == 0) || (strcmp(name, "/usr/libexec/ios_diagnostics_relay") == 0) || (strcmp(name, "/usr/libexec/networkd") == 0) || (strcmp(name, "/usr/libexec/networkd_privileged") == 0) || (strcmp(name, "/usr/libexec/uuidpathd") == 0) || (strcmp(name, "/private/var/root") == 0) || (strcmp(name, "/private/var/mobile") == 0) || (strcmp(name, "/private/var/mobile/Library") == 0) || (strcmp(name, "/private/var/mobile/Library/Caches") == 0) || (strcmp(name, "/private/var/keybags") == 0) || (strcmp(name, "/private/var/Keychains/keychain-2.db") == 0) || (strcmp(name, "/private/var/Keychains/TrustStore.sqlite3") == 0) || (strcmp(name, "/dev/disk0s1s1") == 0) || (strcmp(name, "/dev/disk0s1s2") == 0) || (strcmp(name, "/dev/disk4") == 0) /*need more testing*/ || (strcmp(name, "/dev/tty.iap") == 0) /*need more testing*/)
        {
            return 1;
        }
    }
    //NotReadable
    else
    {
        if((strcmp(name, "/") == 0) || (strcmp(name, "/Developer") == 0) || (strcmp(name, "/Library/Ringtones") == 0) || (strcmp(name, "/usr/share") == 0) || (strcmp(name, "/sbin/fsck_exfat") == 0) || (strcmp(name, "/sbin/fsck_hfs") == 0) || (strcmp(name, "/sbin/fsck_msdos") == 0) || (strcmp(name, "/sbin/mount_hfs") == 0) || (strcmp(name, "/sbin/newfs_hfs") == 0) || (strcmp(name, "/usr/lib") == 0) || (strcmp(name, "/System/Library/LaunchDaemons") == 0))
        {
            return 1;
        }
        // /Applications different for versions
    }
    
    //Executable
    if( access( name, X_OK ) != -1 )
    {
        if((strcmp(name, "/bin/df") == 0) || (strcmp(name, "/bin/ps") == 0) || (strcmp(name, "/sbin/fsck") == 0) || (strcmp(name, "/sbin/fsck_exfat") == 0) || (strcmp(name, "/sbin/fsck_hfs") == 0) || (strcmp(name, "/sbin/fsck_msdos") == 0) || (strcmp(name, "/sbin/fstyp") == 0) || (strcmp(name, "/sbin/fstyp_hfs") == 0) || (strcmp(name, "/sbin/launchd") == 0) || (strcmp(name, "/sbin/mount") == 0) || (strcmp(name, "/sbin/mount_hfs") == 0) || (strcmp(name, "/sbin/newfs_hfs") == 0) || (strcmp(name, "/sbin/pfctl") == 0) || (strcmp(name, "/usr/bin/brctl") == 0) || (strcmp(name, "/usr/bin/powerlogHelperd") == 0) || (strcmp(name, "/usr/bin/powerlogd") == 0) || (strcmp(name, "/usr/bin/simulatecrash") == 0) || (strcmp(name, "/usr/bin/sysdiagnose") == 0) || (strcmp(name, "/usr/bin/taskinfo") == 0) || (strcmp(name, "/usr/bin/vm_stat") == 0) || (strcmp(name, "/usr/bin/zprint") == 0) || (strcmp(name, "/usr/sbin/absd") == 0) || (strcmp(name, "/usr/sbin/addNetworkInterface") == 0) || (strcmp(name, "/usr/sbin/aslmanager") == 0) || (strcmp(name, "/usr/sbin/BTAvrcp") == 0) || (strcmp(name, "/usr/sbin/BTLEServer") == 0) || (strcmp(name, "/usr/sbin/BTMap") == 0) || (strcmp(name, "/usr/sbin/BTPbap") == 0) || (strcmp(name, "/usr/sbin/BTServer") == 0) || (strcmp(name, "/usr/sbin/BlueTool") == 0) || (strcmp(name, "/usr/sbin/cfprefsd") == 0) || (strcmp(name, "/usr/sbin/distnoted") == 0) || (strcmp(name, "/usr/sbin/filecoordinationd") == 0) || (strcmp(name, "/usr/sbin/ipconfig") == 0) || (strcmp(name, "/usr/sbin/mDNSResponder") == 0) || (strcmp(name, "/usr/sbin/mDNSResponderHelper") == 0) || (strcmp(name, "/usr/sbin/mediaserverd") == 0) || (strcmp(name, "/usr/sbin/notifyd") == 0) || (strcmp(name, "/usr/sbin/nvram") == 0) || (strcmp(name, "/usr/sbin/pppd") == 0) || (strcmp(name, "/usr/sbin/racoon") == 0) || (strcmp(name, "/usr/sbin/rtadvd") == 0) || (strcmp(name, "/usr/sbin/scselect") == 0) || (strcmp(name, "/usr/sbin/scutil") == 0) || (strcmp(name, "/usr/sbin/spindump") == 0) || (strcmp(name, "/usr/sbin/syslogd") == 0) || (strcmp(name, "/usr/sbin/wifid") == 0) || (strcmp(name, "/usr/sbin/wirelessproxd") == 0) || (strcmp(name, "/usr/sbin/WirelessRadioManagerd") == 0) || (strcmp(name, "/usr/libexec/BackupAgent") == 0) || (strcmp(name, "/usr/libexec/BackupAgent2") == 0) || (strcmp(name, "/usr/libexec/CrashHousekeeping") == 0) || (strcmp(name, "/usr/libexec/DuetHeuristic-BM") == 0) || (strcmp(name, "/usr/libexec/FSTaskScheduler") == 0) || (strcmp(name, "/usr/libexec/FinishRestoreFromBackup") == 0) || (strcmp(name, "/usr/libexec/MobileGestaltHelper") == 0) || (strcmp(name, "/usr/libexec/NANDTaskScheduler") == 0) || (strcmp(name, "/usr/libexec/OTAPKIAssetTool") == 0) || (strcmp(name, "/usr/libexec/OTATaskingAgent") == 0) || (strcmp(name, "/usr/libexec/PreboardService") == 0) || (strcmp(name, "/usr/libexec/ProxiedCrashCopier") == 0) || (strcmp(name, "/usr/libexec/PurpleReverseProxy") == 0) || (strcmp(name, "/usr/libexec/SafariCloudHistoryPushAgent") == 0) || (strcmp(name, "/usr/libexec/SyncAgent") == 0) || (strcmp(name, "/usr/libexec/UserEventAgent") == 0) || (strcmp(name, "/usr/libexec/adid") == 0) || (strcmp(name, "/usr/libexec/afcd") == 0) || (strcmp(name, "/usr/libexec/aitd") == 0) || (strcmp(name, "/usr/libexec/amfid") == 0) || (strcmp(name, "/usr/libexec/assertiond") == 0) || (strcmp(name, "/usr/libexec/atc") == 0) || (strcmp(name, "/usr/libexec/atwakeup") == 0) || (strcmp(name, "/usr/libexec/backboardd") == 0) || (strcmp(name, "/usr/libexec/biometrickitd") == 0) || (strcmp(name, "/usr/libexec/bootpd") == 0) || (strcmp(name, "/usr/libexec/bubbled") == 0) || (strcmp(name, "/usr/libexec/cc_fips_test") == 0) || (strcmp(name, "/usr/libexec/checkpointd") == 0) || (strcmp(name, "/usr/libexec/companion_proxy") == 0) || (strcmp(name, "/usr/libexec/configd") == 0) || (strcmp(name, "/usr/libexec/corecaptured") == 0) || (strcmp(name, "/usr/libexec/coreduetd") == 0) || (strcmp(name, "/usr/libexec/crash_mover") == 0) || (strcmp(name, "/usr/libexec/demod") == 0) || (strcmp(name, "/usr/libexec/demod_helper") == 0) || (strcmp(name, "/usr/libexec/dhcpd") == 0) || (strcmp(name, "/usr/libexec/diagnosticd") == 0) || (strcmp(name, "/usr/libexec/duetexpertd") == 0) || (strcmp(name, "/usr/libexec/findmydeviced") == 0) || (strcmp(name, "/usr/libexec/fmfd") == 0) || (strcmp(name, "/usr/libexec/fseventsd") == 0) || (strcmp(name, "/usr/libexec/ftp-proxy") == 0) || (strcmp(name, "/usr/libexec/gamecontrollerd") == 0) || (strcmp(name, "/usr/libexec/gamed") == 0) || (strcmp(name, "/usr/libexec/hangreporter") == 0) || (strcmp(name, "/usr/libexec/hangtracerd") == 0) || (strcmp(name, "/usr/libexec/hostapd") == 0) || (strcmp(name, "/usr/libexec/idamd") == 0) || (strcmp(name, "/usr/libexec/ifccd") == 0) || (strcmp(name, "/usr/libexec/init_data_protection") == 0) || (strcmp(name, "/usr/libexec/installd") == 0) || (strcmp(name, "/usr/libexec/ioupsd") == 0) || (strcmp(name, "/usr/libexec/keybagd") == 0) || (strcmp(name, "/usr/libexec/languageassetd") == 0) || (strcmp(name, "/usr/libexec/limitadtrackingd") == 0) || (strcmp(name, "/usr/libexec/locationd") == 0) || (strcmp(name, "/usr/libexec/lockbot") == 0) || (strcmp(name, "/usr/libexec/lockdownd") == 0) || (strcmp(name, "/usr/libexec/logd") == 0) || (strcmp(name, "/usr/libexec/lsd") == 0) || (strcmp(name, "/usr/libexec/lskdd") == 0) || (strcmp(name, "/usr/libexec/lskdmsed") == 0) || (strcmp(name, "/usr/libexec/mailq") == 0) || (strcmp(name, "/usr/libexec/mc_mobile_tunnel") == 0) || (strcmp(name, "/usr/libexec/misagent") == 0) || (strcmp(name, "/usr/libexec/misd") == 0) || (strcmp(name, "/usr/libexec/mmaintenanced") == 0) || (strcmp(name, "/usr/libexec/mobile_assertion_agent") == 0) || (strcmp(name, "/usr/libexec/mobile_diagnostics_relay") == 0) || (strcmp(name, "/usr/libexec/mobile_ le_relay") == 0) || (strcmp(name, "/usr/libexec/mobile_house_arrest") == 0) || (strcmp(name, "/usr/libexec/mobile_installation_proxy") == 0) || (strcmp(name, "/usr/libexec/mobile_obliterator") == 0) || (strcmp(name, "/usr/libexec/mobile_storage_proxy") == 0) || (strcmp(name, "/usr/libexec/mobileactivationd") == 0) || (strcmp(name, "/usr/libexec/mobileassetd") == 0) || (strcmp(name, "/usr/libexec/mtmergeprops") == 0) || (strcmp(name, "/usr/libexec/neagent") == 0) || (strcmp(name, "/usr/libexec/nehelper") == 0) || (strcmp(name, "/usr/libexec/nesessionmanager") == 0) || (strcmp(name, "/usr/libexec/nfcd") == 0) || (strcmp(name, "/usr/libexec/nlcd") == 0) || (strcmp(name, "/usr/libexec/notification_proxy") == 0) || (strcmp(name, "/usr/libexec/nsurlsessiond") == 0) || (strcmp(name, "/usr/libexec/nsurlstoraged") == 0) || (strcmp(name, "/usr/libexec/online-auth-agent") == 0) || (strcmp(name, "/usr/libexec/oscard") == 0) || (strcmp(name, "/usr/libexec/pcapd") == 0) || (strcmp(name, "/usr/libexec/pfd") == 0) || (strcmp(name, "/usr/libexec/pipelined") == 0) || (strcmp(name, "/usr/libexec/pkd") == 0) || (strcmp(name, "/usr/libexec/pkreporter") == 0) || (strcmp(name, "/usr/libexec/ptpd") == 0) || (strcmp(name, "/usr/libexec/replayd") == 0) || (strcmp(name, "/usr/libexec/rolld") == 0) || (strcmp(name, "/usr/libexec/routined") == 0) || (strcmp(name, "/usr/libexec/rtcreportingd") == 0) || (strcmp(name, "/usr/libexec/securityd") == 0) || (strcmp(name, "/usr/libexec/seld") == 0) || (strcmp(name, "/usr/libexec/seputil") == 0) || (strcmp(name, "/usr/libexec/sharingd") == 0) || (strcmp(name, "/usr/libexec/splashboardd") == 0) || (strcmp(name, "/usr/libexec/springboardservicesrelay") == 0) || (strcmp(name, "/usr/libexec/streaming_zip_conduit") == 0) || (strcmp(name, "/usr/libexec/swcd") == 0) || (strcmp(name, "/usr/libexec/symptomsd") == 0) || (strcmp(name, "/usr/libexec/symptomsd-helper") == 0) || (strcmp(name, "/usr/libexec/syslog_relay") == 0) || (strcmp(name, "/usr/libexec/sysstatuscheck") == 0) || (strcmp(name, "/usr/libexec/timed") == 0) || (strcmp(name, "/usr/libexec/tipsd") == 0) || (strcmp(name, "/usr/libexec/transitd") == 0) || (strcmp(name, "/usr/libexec/tzd") == 0) || (strcmp(name, "/usr/libexec/tzinit") == 0) || (strcmp(name, "/usr/libexec/tzlinkd") == 0) || (strcmp(name, "/usr/libexec/wapic") == 0) || (strcmp(name, "/usr/libexec/webinspectord") == 0) || (strcmp(name, "/usr/libexec/wifiFirmwareLoader") == 0) || (strcmp(name, "/usr/libexec/xpcproxy") == 0) || (strcmp(name, "/usr/libexec/aosnotifyd") == 0) || (strcmp(name, "/usr/libexec/findmydeviced-nano-support") == 0) || (strcmp(name, "/usr/libexec/ios_diagnostics_relay") == 0) || (strcmp(name, "/usr/libexec/networkd") == 0) || (strcmp(name, "/usr/libexec/networkd_privileged") == 0) || (strcmp(name, "/usr/libexec/uuidpathd") == 0) || (strcmp(name, "/private/var/keybags") == 0) || (strcmp(name, "/private/var/Keychains/keychain-2.db") == 0) || (strcmp(name, "/private/var/Keychains/TrustStore.sqlite3") == 0) || (strcmp(name, "/dev/disk0s1s1") == 0) || (strcmp(name, "/dev/disk0s1s2") == 0) || (strcmp(name, "/dev/disk4") == 0) || (strcmp(name, "/etc/fstab") == 0) /*need more testing*/ || (strcmp(name, "/dev/tty.iap") == 0) /*need more testing*/)
        {
            return 1;
        }
    }
    //NotExecutable
    else
    {
        if((strcmp(name, "/") == 0) || (strcmp(name, "/Applications") == 0) || (strcmp(name, "/Developer") == 0) || (strcmp(name, "/Library") == 0) || (strcmp(name, "/System") == 0) || (strcmp(name, "/bin") == 0) || (strcmp(name, "/cores") == 0) || (strcmp(name, "/dev") == 0) || (strcmp(name, "/etc") == 0) || (strcmp(name, "/private") == 0) || (strcmp(name, "/sbin") == 0) || (strcmp(name, "/tmp") == 0) || (strcmp(name, "/usr") == 0) || (strcmp(name, "/var") == 0) || (strcmp(name, "/var/mobile/Containers/Data/Application") == 0) || (strcmp(name, "/var/mobile/Containers/Bundle/Application") == 0) || (strcmp(name, "/var/containers/Bundle/Application") == 0) || (strcmp(name, "/Library/Keychains") == 0) || (strcmp(name, "/private/var/Keychains") == 0) || (strcmp(name, "/private/var") == 0) || (strcmp(name, "/usr/bin") == 0) || (strcmp(name, "/usr/sbin") == 0) || (strcmp(name, "/System") == 0) || (strcmp(name, "/System") == 0) || (strcmp(name, "/Library/Ringtones") == 0) || (strcmp(name, "/Library/Wallpaper") == 0) || (strcmp(name, "/usr/libexec") == 0) || (strcmp(name, "/usr/share") == 0) || (strcmp(name, "/usr/lib") == 0) || (strcmp(name, "/Library/LaunchAgents") == 0) || (strcmp(name, "/System/Library/LaunchDaemons") == 0) || (strcmp(name, "/private/var/root") == 0) || (strcmp(name, "/private/var/mobile") == 0) || (strcmp(name, "/private/var/mobile/Library") == 0) || (strcmp(name, "/private/var/mobile/Library/Caches") == 0))
        {
            return 1;
        }
    }

    //Writeable
    if( access( name, W_OK ) != -1 )
    {
        // Nothing should be writable
        return 1;
    }
    //NotWritable
    else
    {
        // Nothing is writable
    }
    
    return 0;
}

int checkFileStat(char* name)
{
    struct stat st;
    
    //Size
    if(lstat(name,&st) >= 0)
    {
        if(strcmp(name, "/") == 0)
        {
            if(st.st_size > 748)
                return 1;
        }
//        if(strcmp(name, "/Developer") == 0)
//        {
//            if(st.st_size != 340)
//                return 1;
//        }
 
        
        /*need more testing*/
        if(strcmp(name, "/dev/tty.iap") == 0)
        {
            if(st.st_size == 0)
                return 1;
        }
        /*need more testing*/
        
        if(strcmp(name, "/bin") == 0)
        {
            if(st.st_size > 136)
                return 1;
        }
        if((strcmp(name, "/cores") == 0) || (strcmp(name, "/Library/LaunchAgents") == 0))
        {
            if(st.st_size != 68)
                return 1;
        }
        if((strcmp(name, "/etc") == 0) || (strcmp(name, "/var") == 0))
        {
            if(st.st_size != 11)
                return 1;
        }
        if((strcmp(name, "/sbin") == 0) || (strcmp(name, "/usr/share") == 0))
        {
            if(st.st_size > 442)
                return 1;
        }
        if(strcmp(name, "/tmp") == 0)
        {
            if(st.st_size != 15)
                return 1;
        }
        if(strcmp(name, "/private/var/keybags") == 0)
        {
            if(st.st_size != 136)
                return 1;
        }
        if((strcmp(name, "/Library/Keychains") == 0) || (strcmp(name, "/usr/libexec/aosnotifyd") == 0) || (strcmp(name, "/usr/libexec/findmydeviced-nano-support") == 0) || (strcmp(name, "/usr/libexec/ios_diagnostics_relay") == 0) || (strcmp(name, "/usr/libexec/networkd") == 0) || (strcmp(name, "/usr/libexec/networkd_privileged") == 0) || (strcmp(name, "/usr/libexec/uuidpathd") == 0))
        {
            if(st.st_size != 24)
                return 1;
        }
        if((strcmp(name, "/dev/disk0s1s1") == 0) || (strcmp(name, "/dev/disk0s1s2") == 0) || (strcmp(name, "/dev/disk4") == 0))
        {
            if(st.st_size == 0)
                return 1;
        }
        if((strcmp(name, "/sbin/fsck_exfat") == 0) || (strcmp(name, "/sbin/fsck_msdos") == 0))
        {
            if(st.st_size != 66)
                return 1;
        }
        if(strcmp(name, "/sbin/fsck_hfs") == 0)
        {
            if(st.st_size != 62)
                return 1;
        }
        if((strcmp(name, "/sbin/mount_hfs") == 0) || (strcmp(name, "/sbin/newfs_hfs") == 0))
        {
            if(st.st_size != 63)
                return 1;
        }
        if(strcmp(name, "/usr/libexec/init_data_protection") == 0)
        {
            if(st.st_size != 7)
                return 1;
        }
//        if(!(strcmp(name, "/private/var/root")))
//        {
//            if(st.st_size > 238)
//                return 1;
//        }
        
        //chmod stuff
        if((strcmp(name, "/Applications") == 0) || (strcmp(name, "/Library") == 0) || (strcmp(name, "/Library/Ringtones") == 0) || (strcmp(name, "/Library/Wallpaper") == 0))
        {
            if(st.st_mode != 040775)
                return 1;
        }
        if((strcmp(name, "/Developer") == 0) || (strcmp(name, "/cores") == 0))
        {
            if(st.st_mode != 041775)
                return 1;
        }
        if((strcmp(name, "/System") == 0) || (strcmp(name, "/bin") == 0) || (strcmp(name, "/private") == 0) || (strcmp(name, "/sbin") == 0) || (strcmp(name, "/usr") == 0) || (strcmp(name, "/var/mobile/Containers/Data/Application") == 0) || (strcmp(name, "/var/mobile/Containers/Bundle/Application") == 0) || (strcmp(name, "/var/containers/Bundle/Application") == 0) || (strcmp(name, "/private/var/Keychains") == 0) || (strcmp(name, "/private/var") == 0) || (strcmp(name, "/usr/bin") == 0) || (strcmp(name, "/usr/sbin") == 0) || (strcmp(name, "/usr/libexec") == 0) || (strcmp(name, "/usr/share") == 0) || (strcmp(name, "/usr/lib") == 0)  || (strcmp(name, "/Library/LaunchAgents") == 0) || (strcmp(name, "/System/Library/LaunchDaemons") == 0) || (strcmp(name, "/private/var/root") == 0))
        {
            if(st.st_mode != 040755)
                return 1;
        }
        if(strcmp(name, "/dev") == 0)
        {
            if(st.st_mode != 040555)
                return 1;
        }
        if((strcmp(name, "/private/var/mobile") == 0) || (strcmp(name, "/private/var/mobile/Library") == 0))
        {
            if(st.st_mode != 040711)
                return 1;
        }
        if((strcmp(name, "/etc") == 0) || (strcmp(name, "/tmp") == 0) || (strcmp(name, "/var") == 0) || (strcmp(name, "/Library/Keychains") == 0) || (strcmp(name, "/sbin/fsck_hfs") == 0) || (strcmp(name, "/sbin/mount_hfs") == 0) || (strcmp(name, "/sbin/newfs_hfs") == 0) || (strcmp(name, "/usr/libexec/init_data_protection") == 0))
        {
            if(st.st_mode != 0120755)
                return 1;
        }
        if((strcmp(name, "/private/var/keybags") == 0) || (strcmp(name, "/private/var/mobile/Library/Caches") == 0))
        {
            if(st.st_mode != 040700)
                return 1;
        }
        if((strcmp(name, "/private/var/Keychains/keychain-2.db") == 0) || (strcmp(name, "/private/var/Keychains/TrustStore.sqlite3") == 0) || (strcmp(name, "/dev/disk0s1s1") == 0) || (strcmp(name, "/dev/disk0s1s2") == 0) || (strcmp(name, "/dev/disk4") == 0) || (strcmp(name, "/etc/fstab") == 0) || (strcmp(name, "/bin/df") == 0) || (strcmp(name, "/bin/ps") == 0) || (strcmp(name, "/sbin/fsck") == 0) || (strcmp(name, "/sbin/fstyp") == 0) || (strcmp(name, "/sbin/fstyp_hfs") == 0) || (strcmp(name, "/sbin/launchd") == 0) || (strcmp(name, "/sbin/mount") == 0) || (strcmp(name, "/sbin/pfctl") == 0) || (strcmp(name, "/usr/bin/brctl") == 0) || (strcmp(name, "/usr/bin/powerlogHelperd") == 0) || (strcmp(name, "/usr/bin/powerlogd") == 0) || (strcmp(name, "/usr/bin/simulatecrash") == 0) || (strcmp(name, "/usr/bin/sysdiagnose") == 0) || (strcmp(name, "/usr/bin/taskinfo") == 0) || (strcmp(name, "/usr/bin/vm_stat") == 0) || (strcmp(name, "/usr/bin/zprint") == 0) || (strcmp(name, "/usr/sbin/absd") == 0) || (strcmp(name, "/usr/sbin/addNetworkInterface") == 0) || (strcmp(name, "/usr/sbin/aslmanager") == 0) || (strcmp(name, "/usr/sbin/BTAvrcp") == 0) || (strcmp(name, "/usr/sbin/BTLEServer") == 0) || (strcmp(name, "/usr/sbin/BTMap") == 0) || (strcmp(name, "/usr/sbin/BTPbap") == 0) || (strcmp(name, "/usr/sbin/BTServer") == 0) || (strcmp(name, "/usr/sbin/BlueTool") == 0) || (strcmp(name, "/usr/sbin/cfprefsd") == 0) || (strcmp(name, "/usr/sbin/distnoted") == 0) || (strcmp(name, "/usr/sbin/filecoordinationd") == 0) || (strcmp(name, "/usr/sbin/ipconfig") == 0) || (strcmp(name, "/usr/sbin/mDNSResponder") == 0) || (strcmp(name, "/usr/sbin/mDNSResponderHelper") == 0) || (strcmp(name, "/usr/sbin/mediaserverd") == 0) || (strcmp(name, "/usr/sbin/notifyd") == 0) || (strcmp(name, "/usr/sbin/nvram") == 0) || (strcmp(name, "/usr/sbin/pppd") == 0) || (strcmp(name, "/usr/sbin/racoon") == 0) || (strcmp(name, "/usr/sbin/rtadvd") == 0) || (strcmp(name, "/usr/sbin/scselect") == 0) || (strcmp(name, "/usr/sbin/scutil") == 0) || (strcmp(name, "/usr/sbin/spindump") == 0) || (strcmp(name, "/usr/sbin/syslogd") == 0) || (strcmp(name, "/usr/sbin/wifid") == 0) || (strcmp(name, "/usr/sbin/wirelessproxd") == 0) || (strcmp(name, "/usr/sbin/WirelessRadioManagerd") == 0) || (strcmp(name, "/usr/libexec/BackupAgent") == 0) || (strcmp(name, "/usr/libexec/BackupAgent2") == 0) || (strcmp(name, "/usr/libexec/CrashHousekeeping") == 0) || (strcmp(name, "/usr/libexec/DuetHeuristic-BM") == 0) || (strcmp(name, "/usr/libexec/FSTaskScheduler") == 0) || (strcmp(name, "/usr/libexec/FinishRestoreFromBackup") == 0) || (strcmp(name, "/usr/libexec/MobileGestaltHelper") == 0) || (strcmp(name, "/usr/libexec/NANDTaskScheduler") == 0) || (strcmp(name, "/usr/libexec/OTAPKIAssetTool") == 0) || (strcmp(name, "/usr/libexec/OTATaskingAgent") == 0) || (strcmp(name, "/usr/libexec/PreboardService") == 0) || (strcmp(name, "/usr/libexec/ProxiedCrashCopier") == 0) || (strcmp(name, "/usr/libexec/PurpleReverseProxy") == 0) || (strcmp(name, "/usr/libexec/SafariCloudHistoryPushAgent") == 0) || (strcmp(name, "/usr/libexec/SyncAgent") == 0) || (strcmp(name, "/usr/libexec/UserEventAgent") == 0) || (strcmp(name, "/usr/libexec/adid") == 0) || (strcmp(name, "/usr/libexec/afcd") == 0) || (strcmp(name, "/usr/libexec/aitd") == 0) || (strcmp(name, "/usr/libexec/amfid") == 0) || (strcmp(name, "/usr/libexec/assertiond") == 0) || (strcmp(name, "/usr/libexec/atc") == 0) || (strcmp(name, "/usr/libexec/atwakeup") == 0) || (strcmp(name, "/usr/libexec/backboardd") == 0) || (strcmp(name, "/usr/libexec/biometrickitd") == 0) || (strcmp(name, "/usr/libexec/bootpd") == 0) || (strcmp(name, "/usr/libexec/bubbled") == 0) || (strcmp(name, "/usr/libexec/cc_fips_test") == 0) || (strcmp(name, "/usr/libexec/checkpointd") == 0) || (strcmp(name, "/usr/libexec/companion_proxy") == 0) || (strcmp(name, "/usr/libexec/configd") == 0) || (strcmp(name, "/usr/libexec/corecaptured") == 0) || (strcmp(name, "/usr/libexec/coreduetd") == 0) || (strcmp(name, "/usr/libexec/crash_mover") == 0) || (strcmp(name, "/usr/libexec/demod") == 0) || (strcmp(name, "/usr/libexec/demod_helper") == 0) || (strcmp(name, "/usr/libexec/dhcpd") == 0) || (strcmp(name, "/usr/libexec/diagnosticd") == 0) || (strcmp(name, "/usr/libexec/duetexpertd") == 0) || (strcmp(name, "/usr/libexec/findmydeviced") == 0) || (strcmp(name, "/usr/libexec/fmfd") == 0) || (strcmp(name, "/usr/libexec/fseventsd") == 0) || (strcmp(name, "/usr/libexec/ftp-proxy") == 0) || (strcmp(name, "/usr/libexec/gamecontrollerd") == 0) || (strcmp(name, "/usr/libexec/gamed") == 0) || (strcmp(name, "/usr/libexec/hangreporter") == 0) || (strcmp(name, "/usr/libexec/hangtracerd") == 0) || (strcmp(name, "/usr/libexec/hostapd") == 0) || (strcmp(name, "/usr/libexec/idamd") == 0) || (strcmp(name, "/usr/libexec/ifccd") == 0) || (strcmp(name, "/usr/libexec/installd") == 0) || (strcmp(name, "/usr/libexec/ioupsd") == 0) || (strcmp(name, "/usr/libexec/keybagd") == 0) || (strcmp(name, "/usr/libexec/languageassetd") == 0) || (strcmp(name, "/usr/libexec/limitadtrackingd") == 0) || (strcmp(name, "/usr/libexec/locationd") == 0) || (strcmp(name, "/usr/libexec/lockbot") == 0) || (strcmp(name, "/usr/libexec/lockdownd") == 0) || (strcmp(name, "/usr/libexec/logd") == 0) || (strcmp(name, "/usr/libexec/lsd") == 0) || (strcmp(name, "/usr/libexec/lskdd") == 0) || (strcmp(name, "/usr/libexec/lskdmsed") == 0) || (strcmp(name, "/usr/libexec/mailq") == 0) || (strcmp(name, "/usr/libexec/mc_mobile_tunnel") == 0) || (strcmp(name, "/usr/libexec/misagent") == 0) || (strcmp(name, "/usr/libexec/misd") == 0) || (strcmp(name, "/usr/libexec/mmaintenanced") == 0) || (strcmp(name, "/usr/libexec/mobile_assertion_agent") == 0) || (strcmp(name, "/usr/libexec/mobile_diagnostics_relay") == 0) || (strcmp(name, "/usr/libexec/mobile_file_relay") == 0) || (strcmp(name, "/usr/libexec/mobile_house_arrest") == 0) || (strcmp(name, "/usr/libexec/mobile_installation_proxy") == 0) || (strcmp(name, "/usr/libexec/mobile_obliterator") == 0) || (strcmp(name, "/usr/libexec/mobile_storage_proxy") == 0) || (strcmp(name, "/usr/libexec/mobileactivationd") == 0) || (strcmp(name, "/usr/libexec/mobileassetd") == 0) || (strcmp(name, "/usr/libexec/mtmergeprops") == 0) || (strcmp(name, "/usr/libexec/neagent") == 0) || (strcmp(name, "/usr/libexec/nehelper") == 0) || (strcmp(name, "/usr/libexec/nesessionmanager") == 0) || (strcmp(name, "/usr/libexec/nfcd") == 0) || (strcmp(name, "/usr/libexec/nlcd") == 0) || (strcmp(name, "/usr/libexec/notification_proxy") == 0) || (strcmp(name, "/usr/libexec/nsurlsessiond") == 0) || (strcmp(name, "/usr/libexec/nsurlstoraged") == 0) || (strcmp(name, "/usr/libexec/online-auth-agent") == 0) || (strcmp(name, "/usr/libexec/oscard") == 0) || (strcmp(name, "/usr/libexec/pcapd") == 0) || (strcmp(name, "/usr/libexec/pfd") == 0) || (strcmp(name, "/usr/libexec/pipelined") == 0) || (strcmp(name, "/usr/libexec/pkd") == 0) || (strcmp(name, "/usr/libexec/pkreporter") == 0) || (strcmp(name, "/usr/libexec/ptpd") == 0) || (strcmp(name, "/usr/libexec/replayd") == 0) || (strcmp(name, "/usr/libexec/rolld") == 0) || (strcmp(name, "/usr/libexec/routined") == 0) || (strcmp(name, "/usr/libexec/rtcreportingd") == 0) || (strcmp(name, "/usr/libexec/securityd") == 0) || (strcmp(name, "/usr/libexec/seld") == 0) || (strcmp(name, "/usr/libexec/seputil") == 0) || (strcmp(name, "/usr/libexec/sharingd") == 0) || (strcmp(name, "/usr/libexec/splashboardd") == 0) || (strcmp(name, "/usr/libexec/springboardservicesrelay") == 0) || (strcmp(name, "/usr/libexec/streaming_zip_conduit") == 0) || (strcmp(name, "/usr/libexec/swcd") == 0) || (strcmp(name, "/usr/libexec/symptomsd") == 0) || (strcmp(name, "/usr/libexec/symptomsd-helper") == 0) || (strcmp(name, "/usr/libexec/syslog_relay") == 0) || (strcmp(name, "/usr/libexec/sysstatuscheck") == 0) || (strcmp(name, "/usr/libexec/timed") == 0) || (strcmp(name, "/usr/libexec/tipsd") == 0) || (strcmp(name, "/usr/libexec/transitd") == 0) || (strcmp(name, "/usr/libexec/tzd") == 0) || (strcmp(name, "/usr/libexec/tzinit") == 0) || (strcmp(name, "/usr/libexec/tzlinkd") == 0) || (strcmp(name, "/usr/libexec/wapic") == 0) || (strcmp(name, "/usr/libexec/webinspectord") == 0) || (strcmp(name, "/usr/libexec/wifiFirmwareLoader") == 0) || (strcmp(name, "/usr/libexec/xpcproxy") == 0) || (strcmp(name, "/usr/libexec/aosnotifyd") == 0) || (strcmp(name, "/usr/libexec/findmydeviced-nano-support") == 0) || (strcmp(name, "/usr/libexec/ios_diagnostics_relay") == 0) || (strcmp(name, "/usr/libexec/networkd") == 0) || (strcmp(name, "/usr/libexec/networkd_privileged") == 0) || (strcmp(name, "/usr/libexec/uuidpathd") == 0) /*need more testing*/ || (strcmp(name, "/dev/tty.iap") == 0) /*need more testing*/)
        {
            if(st.st_mode != 01)
                return 1;
        }
        if((strcmp(name, "/sbin/fsck_exfat") == 0) || (strcmp(name, "/sbin/fsck_msdos") == 0))
        {
            if(!(S_ISLNK(st.st_mode)))
                return 1;
        }        
    }
    return 0;
}

int checkFileExistence(char* name)
{
    if( access( name, F_OK ) != -1 )
        return 1;
    return 0;
}

int spawnProcess()
{
    pid_t pid;
    char *argv[] = {"df", "", "", NULL};
    int status=posix_spawn(&pid, "/bin/df", NULL, NULL, argv, NULL);
    if(status==0)
        return 1;
    
    char *argv1[] = {"ps", "", "", NULL};
    int status1=posix_spawn(&pid, "/bin/ps", NULL, NULL, argv1, NULL);
    if(status1==0)
        return 1;
    
    char *argv2[] = {"taskinfo", "", "", NULL};
    int status2=posix_spawn(&pid, "/usr/bin/taskinfo", NULL, NULL, argv2, NULL);
    if(status2==0)
        return 1;
    
    char *argv3[] = {"vm_stat", "", "", NULL};
    int status3=posix_spawn(&pid, "/usr/bin/vm_stat", NULL, NULL, argv3, NULL);
    if(status3==0)
        return 1;
    
    char *argv4[] = {"ipconfig", "ifcount", "", NULL};
    int status4=posix_spawn(&pid, "/usr/sbin/ipconfig", NULL, NULL, argv4, NULL);
    if(status4==0)
        return 1;
    
    char *argv5[] = {"syslogd", "", "", NULL};
    int status5=posix_spawn(&pid, "/usr/sbin/syslogd", NULL, NULL, argv5, NULL);
    if(status5==0)
        return 1;
    
    char *argv6[] = {"mDNSResponder", "", "", NULL};
    int status6=posix_spawn(&pid, "/usr/sbin/mDNSResponder", NULL, NULL, argv6, NULL);
    if(status6==0)
        return 1;
    
    if(fork() >= 0)
        return 1;
    
    return 0;
}

int loadedLibraries()
{
    for (int i = 0; i < _dyld_image_count(); i++)
    {
        const char *dyld = _dyld_get_image_name(i);
        if(strstr(dyld, "MobileSubstrate") || strstr(dyld, "cynject") || strstr(dyld, "AppList") || strstr(dyld, "CustomWidgetIcons") || strstr(dyld, "MobileSafety") || strstr(dyld, "OpenSiri") || strstr(dyld, "PreferenceLoader") || strstr(dyld, "RocketBootstrap") || strstr(dyld, "SSLKillSwitch") || strstr(dyld, "SSLKillSwitch2") || strstr(dyld, "WeeLoader") || strstr(dyld, "patcyh"))
        {
            return 1;
        }
    }
    
    char *env = getenv("DYLD_INSERT_LIBRARIES");
    if(env)
        return 1;
    return 0;
}

// Tested only on Non-JB (iOS 11.2) and JB (iOS 9.3.3). Need more testing.
int ttySerialPort()
{
    int fileDescriptor = open("/dev/tty.iap", O_RDWR | O_NOCTTY | O_NONBLOCK);
    if (fileDescriptor == -1 && errno==1)
    {
//        printf("\nError opening serial port %s - %s(%d).\n", "/dev/tty.iap", strerror(errno), errno);
//        printf("\nError opening serial port /dev/tty.iap - Operation not permitted(1).");
        printf("\nNon-Jailbroken, but not fully sure.");
        return 0;
    }
    printf("\nJailbroken, but not fully sure.");
    return 1;
}
