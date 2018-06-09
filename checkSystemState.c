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
    int fd = open(name,O_RDONLY);
    
    //NotExist
    if( access( name, F_OK ) == -1 )
    {
        if(!(strcmp(name, "/") || strcmp(name, "/Applications") || strcmp(name, "/Developer") || strcmp(name, "/Library") || strcmp(name, "/System") || strcmp(name, "/bin") || strcmp(name, "/cores") || strcmp(name, "/dev") || strcmp(name, "/etc") || strcmp(name, "/private") || strcmp(name, "/sbin") || strcmp(name, "/tmp") || strcmp(name, "/usr") || strcmp(name, "/var") || strcmp(name, "/var/mobile/Containers/Data/Application") || strcmp(name, "/private/var/keybags") || strcmp(name, "/Library/Keychains") || strcmp(name, "/private/var/Keychains") || strcmp(name, "/private/var/Keychains/keychain-2.db") || strcmp(name, "/private/var/Keychains/TrustStore.sqlite3") || strcmp(name, "/private/var") || strcmp(name, "/dev/disk0s1s1") || strcmp(name, "/dev/disk0s1s2") || strcmp(name, "/etc/fstab") || strcmp(name, "/usr/bin") || strcmp(name, "/usr/sbin") || strcmp(name, "/Library/Ringtones") || strcmp(name, "/Library/Wallpaper") || strcmp(name, "/usr/libexec") || strcmp(name, "/usr/share") || strcmp(name, "/bin/df") || strcmp(name, "/bin/ps") || strcmp(name, "/sbin/fsck") || strcmp(name, "/sbin/fsck_exfat") || strcmp(name, "/sbin/fsck_hfs") || strcmp(name, "/sbin/fsck_msdos") || strcmp(name, "/sbin/fstyp") || strcmp(name, "/sbin/fstyp_hfs") || strcmp(name, "/sbin/launchd") || strcmp(name, "/sbin/mount") || strcmp(name, "/sbin/mount_hfs") || strcmp(name, "/sbin/newfs_hfs") || strcmp(name, "/sbin/pfctl") || strcmp(name, "/usr/bin/brctl") || strcmp(name, "/usr/bin/powerlogHelperd") || strcmp(name, "/usr/bin/powerlogd") || strcmp(name, "/usr/bin/simulatecrash") || strcmp(name, "/usr/bin/sysdiagnose") || strcmp(name, "/usr/bin/taskinfo") || strcmp(name, "/usr/bin/vm_stat") || strcmp(name, "/usr/bin/zprint") || strcmp(name, "/usr/sbin/absd") || strcmp(name, "/usr/sbin/addNetworkInterface") || strcmp(name, "/usr/sbin/aslmanager") || strcmp(name, "/usr/sbin/BTAvrcp") || strcmp(name, "/usr/sbin/BTLEServer") || strcmp(name, "/usr/sbin/BTMap") || strcmp(name, "/usr/sbin/BTPbap") || strcmp(name, "/usr/sbin/BTServer") || strcmp(name, "/usr/sbin/BlueTool") || strcmp(name, "/usr/sbin/cfprefsd") || strcmp(name, "/usr/sbin/distnoted") || strcmp(name, "/usr/sbin/filecoordinationd") || strcmp(name, "/usr/sbin/ipconfig") || strcmp(name, "/usr/sbin/mDNSResponder") || strcmp(name, "/usr/sbin/mDNSResponderHelper") || strcmp(name, "/usr/sbin/mediaserverd") || strcmp(name, "/usr/sbin/notifyd") || strcmp(name, "/usr/sbin/nvram") || strcmp(name, "/usr/sbin/pppd") || strcmp(name, "/usr/sbin/racoon") || strcmp(name, "/usr/sbin/rtadvd") || strcmp(name, "/usr/sbin/scselect") || strcmp(name, "/usr/sbin/scutil") || strcmp(name, "/usr/sbin/spindump") || strcmp(name, "/usr/sbin/syslogd") || strcmp(name, "/usr/sbin/wifid") || strcmp(name, "/usr/sbin/wirelessproxd") || strcmp(name, "/usr/sbin/WirelessRadioManagerd") || strcmp(name, "/usr/libexec/BackupAgent") || strcmp(name, "/usr/libexec/BackupAgent2") || strcmp(name, "/usr/libexec/CrashHousekeeping") || strcmp(name, "/usr/libexec/DuetHeuristic-BM") || strcmp(name, "/usr/libexec/FSTaskScheduler") || strcmp(name, "/usr/libexec/FinishRestoreFromBackup") || strcmp(name, "/usr/libexec/MobileGestaltHelper") || strcmp(name, "/usr/libexec/NANDTaskScheduler") || strcmp(name, "/usr/libexec/OTAPKIAssetTool") || strcmp(name, "/usr/libexec/OTATaskingAgent") || strcmp(name, "/usr/libexec/PreboardService") || strcmp(name, "/usr/libexec/ProxiedCrashCopier") || strcmp(name, "/usr/libexec/PurpleReverseProxy") || strcmp(name, "/usr/libexec/SafariCloudHistoryPushAgent") || strcmp(name, "/usr/libexec/SyncAgent") || strcmp(name, "/usr/libexec/UserEventAgent") || strcmp(name, "/usr/libexec/adid") || strcmp(name, "/usr/libexec/afcd") || strcmp(name, "/usr/libexec/aitd") || strcmp(name, "/usr/libexec/amfid") || strcmp(name, "/usr/libexec/assertiond") || strcmp(name, "/usr/libexec/atc") || strcmp(name, "/usr/libexec/atwakeup") || strcmp(name, "/usr/libexec/backboardd") || strcmp(name, "/usr/libexec/biometrickitd") || strcmp(name, "/usr/libexec/bootpd") || strcmp(name, "/usr/libexec/cc_fips_test") || strcmp(name, "/usr/libexec/checkpointd") || strcmp(name, "/usr/libexec/companion_proxy") || strcmp(name, "/usr/libexec/configd") || strcmp(name, "/usr/libexec/corecaptured") || strcmp(name, "/usr/libexec/coreduetd") || strcmp(name, "/usr/libexec/crash_mover") || strcmp(name, "/usr/libexec/demod") || strcmp(name, "/usr/libexec/demod_helper") || strcmp(name, "/usr/libexec/dhcpd") || strcmp(name, "/usr/libexec/diagnosticd") || strcmp(name, "/usr/libexec/duetexpertd") || strcmp(name, "/usr/libexec/findmydeviced") || strcmp(name, "/usr/libexec/fmfd") || strcmp(name, "/usr/libexec/fseventsd") || strcmp(name, "/usr/libexec/ftp-proxy") || strcmp(name, "/usr/libexec/gamecontrollerd") || strcmp(name, "/usr/libexec/gamed") || strcmp(name, "/usr/libexec/hangtracerd") || strcmp(name, "/usr/libexec/hostapd") || strcmp(name, "/usr/libexec/idamd") || strcmp(name, "/usr/libexec/init_data_protection") || strcmp(name, "/usr/libexec/installd") || strcmp(name, "/usr/libexec/ioupsd") || strcmp(name, "/usr/libexec/keybagd") || strcmp(name, "/usr/libexec/languageassetd") || strcmp(name, "/usr/libexec/limitadtrackingd") || strcmp(name, "/usr/libexec/locationd") || strcmp(name, "/usr/libexec/lockbot") || strcmp(name, "/usr/libexec/lockdownd") || strcmp(name, "/usr/libexec/logd") || strcmp(name, "/usr/libexec/lsd") || strcmp(name, "/usr/libexec/lskdd") || strcmp(name, "/usr/libexec/lskdmsed") || strcmp(name, "/usr/libexec/mc_mobile_tunnel") || strcmp(name, "/usr/libexec/misagent") || strcmp(name, "/usr/libexec/misd") || strcmp(name, "/usr/libexec/mmaintenanced") || strcmp(name, "/usr/libexec/mobile_assertion_agent") || strcmp(name, "/usr/libexec/mobile_diagnostics_relay") || strcmp(name, "/usr/libexec/mobile_file_relay") || strcmp(name, "/usr/libexec/mobile_house_arrest") || strcmp(name, "/usr/libexec/mobile_installation_proxy") || strcmp(name, "/usr/libexec/mobile_obliterator") || strcmp(name, "/usr/libexec/mobile_storage_proxy") || strcmp(name, "/usr/libexec/mobileassetd") || strcmp(name, "/usr/libexec/mtmergeprops") || strcmp(name, "/usr/libexec/neagent") || strcmp(name, "/usr/libexec/nehelper") || strcmp(name, "/usr/libexec/nesessionmanager") || strcmp(name, "/usr/libexec/nfcd") || strcmp(name, "/usr/libexec/nlcd") || strcmp(name, "/usr/libexec/notification_proxy") || strcmp(name, "/usr/libexec/nsurlsessiond") || strcmp(name, "/usr/libexec/nsurlstoraged") || strcmp(name, "/usr/libexec/online-auth-agent") || strcmp(name, "/usr/libexec/oscard") || strcmp(name, "/usr/libexec/pcapd") || strcmp(name, "/usr/libexec/pfd") || strcmp(name, "/usr/libexec/pipelined") || strcmp(name, "/usr/libexec/pkd") || strcmp(name, "/usr/libexec/pkreporter") || strcmp(name, "/usr/libexec/ptpd") || strcmp(name, "/usr/libexec/replayd") || strcmp(name, "/usr/libexec/rolld") || strcmp(name, "/usr/libexec/routined") || strcmp(name, "/usr/libexec/rtcreportingd") || strcmp(name, "/usr/libexec/securityd") || strcmp(name, "/usr/libexec/seld") || strcmp(name, "/usr/libexec/seputil") || strcmp(name, "/usr/libexec/sharingd") || strcmp(name, "/usr/libexec/splashboardd") || strcmp(name, "/usr/libexec/springboardservicesrelay") || strcmp(name, "/usr/libexec/streaming_zip_conduit") || strcmp(name, "/usr/libexec/swcd") || strcmp(name, "/usr/libexec/symptomsd") || strcmp(name, "/usr/libexec/symptomsd-helper") || strcmp(name, "/usr/libexec/syslog_relay") || strcmp(name, "/usr/libexec/sysstatuscheck") || strcmp(name, "/usr/libexec/timed") || strcmp(name, "/usr/libexec/tipsd") || strcmp(name, "/usr/libexec/transitd") || strcmp(name, "/usr/libexec/tzd") || strcmp(name, "/usr/libexec/tzinit") || strcmp(name, "/usr/libexec/tzlinkd") || strcmp(name, "/usr/libexec/wapic") || strcmp(name, "/usr/libexec/webinspectord") || strcmp(name, "/usr/libexec/wifiFirmwareLoader") || strcmp(name, "/usr/libexec/xpcproxy") || strcmp(name, "/usr/lib") || strcmp(name, "/Library/LaunchAgents") || strcmp(name, "/System/Library/LaunchDaemons") || strcmp(name, "/private/var/root") || strcmp(name, "/private/var/mobile") || strcmp(name, "/private/var/mobile/Library") || strcmp(name, "/private/var/mobile/Library/Caches") /*need more testing*/ || strcmp(name, "/dev/tty.iap") /*need more testing*/))
        {
            return 1;
        }
        
        
        // /var/mobile/Containers/Bundle/Application specific for 9.21
        // /var/containers/Bundle/Application, /dev/disk4, /usr/libexec/bubbled, /usr/libexec/hangreporter, /usr/libexec/ifccd, /usr/libexec/mailq, /usr/libexec/mobileactivationd for 9.33 and 10.02
        // /usr/libexec/aosnotifyd, /usr/libexec/findmydeviced-nano-support, /usr/libexec/ios_diagnostics_relay, /usr/libexec/networkd, /usr/libexec/networkd_privileged, /usr/libexec/uuidpathd for 9.21 and 9.33
        return 0;
    }
    
    //Openable
    if(fd >= 0)
    {
        if(!(strcmp(name, "/Library") || strcmp(name, "/System") || strcmp(name, "/bin") || strcmp(name, "/cores") || strcmp(name, "/dev") || strcmp(name, "/etc") || strcmp(name, "/private") || strcmp(name, "/sbin") || strcmp(name, "/tmp") || strcmp(name, "/usr") || strcmp(name, "/var") || strcmp(name, "/var/mobile/Containers/Data/Application") || strcmp(name, "/var/mobile/Containers/Bundle/Application") || strcmp(name, "/var/containers/Bundle/Application") || strcmp(name, "/Library/Keychains") || strcmp(name, "/private/var/Keychains") || strcmp(name, "/private/var") || strcmp(name, "/etc/fstab") || strcmp(name, "/usr/bin") || strcmp(name, "/usr/sbin") || strcmp(name, "/Library/Wallpaper") || strcmp(name, "/usr/libexec") || strcmp(name, "/bin/df") || strcmp(name, "/bin/ps") || strcmp(name, "/sbin/fsck") || strcmp(name, "/sbin/fstyp") || strcmp(name, "/sbin/fstyp_hfs") || strcmp(name, "/sbin/launchd") || strcmp(name, "/sbin/mount") || strcmp(name, "/sbin/pfctl") || strcmp(name, "/usr/bin/brctl") || strcmp(name, "/usr/bin/powerlogHelperd") || strcmp(name, "/usr/bin/powerlogd") || strcmp(name, "/usr/bin/simulatecrash") || strcmp(name, "/usr/bin/sysdiagnose") || strcmp(name, "/usr/bin/taskinfo") || strcmp(name, "/usr/bin/vm_stat") || strcmp(name, "/usr/bin/zprint") || strcmp(name, "/usr/sbin/absd") || strcmp(name, "/usr/sbin/addNetworkInterface") || strcmp(name, "/usr/sbin/aslmanager") || strcmp(name, "/usr/sbin/BTAvrcp") || strcmp(name, "/usr/sbin/BTLEServer") || strcmp(name, "/usr/sbin/BTMap") || strcmp(name, "/usr/sbin/BTPbap") || strcmp(name, "/usr/sbin/BTServer") || strcmp(name, "/usr/sbin/BlueTool") || strcmp(name, "/usr/sbin/cfprefsd") || strcmp(name, "/usr/sbin/distnoted") || strcmp(name, "/usr/sbin/filecoordinationd") || strcmp(name, "/usr/sbin/ipconfig") || strcmp(name, "/usr/sbin/mDNSResponder") || strcmp(name, "/usr/sbin/mDNSResponderHelper") || strcmp(name, "/usr/sbin/mediaserverd") || strcmp(name, "/usr/sbin/notifyd") || strcmp(name, "/usr/sbin/nvram") || strcmp(name, "/usr/sbin/pppd") || strcmp(name, "/usr/sbin/racoon") || strcmp(name, "/usr/sbin/rtadvd") || strcmp(name, "/usr/sbin/scselect") || strcmp(name, "/usr/sbin/scutil") || strcmp(name, "/usr/sbin/spindump") || strcmp(name, "/usr/sbin/syslogd") || strcmp(name, "/usr/sbin/wifid") || strcmp(name, "/usr/sbin/wirelessproxd") || strcmp(name, "/usr/sbin/WirelessRadioManagerd") || strcmp(name, "/usr/libexec/BackupAgent") || strcmp(name, "/usr/libexec/BackupAgent2") || strcmp(name, "/usr/libexec/CrashHousekeeping") || strcmp(name, "/usr/libexec/DuetHeuristic-BM") || strcmp(name, "/usr/libexec/FSTaskScheduler") || strcmp(name, "/usr/libexec/FinishRestoreFromBackup") || strcmp(name, "/usr/libexec/MobileGestaltHelper") || strcmp(name, "/usr/libexec/NANDTaskScheduler") || strcmp(name, "/usr/libexec/OTAPKIAssetTool") || strcmp(name, "/usr/libexec/OTATaskingAgent") || strcmp(name, "/usr/libexec/PreboardService") || strcmp(name, "/usr/libexec/ProxiedCrashCopier") || strcmp(name, "/usr/libexec/PurpleReverseProxy") || strcmp(name, "/usr/libexec/SafariCloudHistoryPushAgent") || strcmp(name, "/usr/libexec/SyncAgent") || strcmp(name, "/usr/libexec/UserEventAgent") || strcmp(name, "/usr/libexec/adid") || strcmp(name, "/usr/libexec/afcd") || strcmp(name, "/usr/libexec/aitd") || strcmp(name, "/usr/libexec/amfid") || strcmp(name, "/usr/libexec/assertiond") || strcmp(name, "/usr/libexec/atc") || strcmp(name, "/usr/libexec/atwakeup") || strcmp(name, "/usr/libexec/backboardd") || strcmp(name, "/usr/libexec/biometrickitd") || strcmp(name, "/usr/libexec/bootpd")|| strcmp(name, "/usr/libexec/bubbled") || strcmp(name, "/usr/libexec/cc_fips_test") || strcmp(name, "/usr/libexec/checkpointd") || strcmp(name, "/usr/libexec/companion_proxy") || strcmp(name, "/usr/libexec/configd") || strcmp(name, "/usr/libexec/corecaptured") || strcmp(name, "/usr/libexec/coreduetd") || strcmp(name, "/usr/libexec/crash_mover") || strcmp(name, "/usr/libexec/demod") || strcmp(name, "/usr/libexec/demod_helper") || strcmp(name, "/usr/libexec/dhcpd") || strcmp(name, "/usr/libexec/diagnosticd") || strcmp(name, "/usr/libexec/duetexpertd") || strcmp(name, "/usr/libexec/findmydeviced") || strcmp(name, "/usr/libexec/fmfd") || strcmp(name, "/usr/libexec/fseventsd") || strcmp(name, "/usr/libexec/ftp-proxy") || strcmp(name, "/usr/libexec/gamecontrollerd") || strcmp(name, "/usr/libexec/gamed") || strcmp(name, "/usr/libexec/hangreporter") || strcmp(name, "/usr/libexec/hangtracerd") || strcmp(name, "/usr/libexec/hostapd") || strcmp(name, "/usr/libexec/idamd") || strcmp(name, "/usr/libexec/ifccd") || strcmp(name, "/usr/libexec/init_data_protection") || strcmp(name, "/usr/libexec/installd") || strcmp(name, "/usr/libexec/ioupsd") || strcmp(name, "/usr/libexec/keybagd") || strcmp(name, "/usr/libexec/languageassetd") || strcmp(name, "/usr/libexec/limitadtrackingd") || strcmp(name, "/usr/libexec/locationd") || strcmp(name, "/usr/libexec/lockbot") || strcmp(name, "/usr/libexec/lockdownd") || strcmp(name, "/usr/libexec/logd") || strcmp(name, "/usr/libexec/lsd") || strcmp(name, "/usr/libexec/lskdd") || strcmp(name, "/usr/libexec/lskdmsed") || strcmp(name, "/usr/libexec/mailq") || strcmp(name, "/usr/libexec/mc_mobile_tunnel") || strcmp(name, "/usr/libexec/misagent") || strcmp(name, "/usr/libexec/misd") || strcmp(name, "/usr/libexec/mmaintenanced") || strcmp(name, "/usr/libexec/mobile_assertion_agent") || strcmp(name, "/usr/libexec/mobile_diagnostics_relay") || strcmp(name, "/usr/libexec/mobile_ le_relay") || strcmp(name, "/usr/libexec/mobile_house_arrest") || strcmp(name, "/usr/libexec/mobile_installation_proxy") || strcmp(name, "/usr/libexec/mobile_obliterator") || strcmp(name, "/usr/libexec/mobile_storage_proxy") || strcmp(name, "/usr/libexec/mobileactivationd") || strcmp(name, "/usr/libexec/mobileassetd") || strcmp(name, "/usr/libexec/mtmergeprops") || strcmp(name, "/usr/libexec/neagent") || strcmp(name, "/usr/libexec/nehelper") || strcmp(name, "/usr/libexec/nesessionmanager") || strcmp(name, "/usr/libexec/nfcd") || strcmp(name, "/usr/libexec/nlcd") || strcmp(name, "/usr/libexec/notification_proxy") || strcmp(name, "/usr/libexec/nsurlsessiond") || strcmp(name, "/usr/libexec/nsurlstoraged") || strcmp(name, "/usr/libexec/online-auth-agent") || strcmp(name, "/usr/libexec/oscard") || strcmp(name, "/usr/libexec/pcapd") || strcmp(name, "/usr/libexec/pfd") || strcmp(name, "/usr/libexec/pipelined") || strcmp(name, "/usr/libexec/pkd") || strcmp(name, "/usr/libexec/pkreporter") || strcmp(name, "/usr/libexec/ptpd") || strcmp(name, "/usr/libexec/replayd") || strcmp(name, "/usr/libexec/rolld") || strcmp(name, "/usr/libexec/routined") || strcmp(name, "/usr/libexec/rtcreportingd") || strcmp(name, "/usr/libexec/securityd") || strcmp(name, "/usr/libexec/seld") || strcmp(name, "/usr/libexec/seputil") || strcmp(name, "/usr/libexec/sharingd") || strcmp(name, "/usr/libexec/splashboardd") || strcmp(name, "/usr/libexec/springboardservicesrelay") || strcmp(name, "/usr/libexec/streaming_zip_conduit") || strcmp(name, "/usr/libexec/swcd") || strcmp(name, "/usr/libexec/symptomsd") || strcmp(name, "/usr/libexec/symptomsd-helper") || strcmp(name, "/usr/libexec/syslog_relay") || strcmp(name, "/usr/libexec/sysstatuscheck") || strcmp(name, "/usr/libexec/timed") || strcmp(name, "/usr/libexec/tipsd") || strcmp(name, "/usr/libexec/transitd") || strcmp(name, "/usr/libexec/tzd") || strcmp(name, "/usr/libexec/tzinit") || strcmp(name, "/usr/libexec/tzlinkd") || strcmp(name, "/usr/libexec/wapic") || strcmp(name, "/usr/libexec/webinspectord") || strcmp(name, "/usr/libexec/wifiFirmwareLoader") || strcmp(name, "/usr/libexec/xpcproxy") || strcmp(name, "/Library/LaunchAgents") || strcmp(name, "/usr/libexec/aosnotifyd") || strcmp(name, "/usr/libexec/findmydeviced-nano-support") || strcmp(name, "/usr/libexec/ios_diagnostics_relay") || strcmp(name, "/usr/libexec/networkd") || strcmp(name, "/usr/libexec/networkd_privileged") || strcmp(name, "/usr/libexec/uuidpathd") || strcmp(name, "/private/var/root") || strcmp(name, "/private/var/mobile") || strcmp(name, "/private/var/mobile/Library") || strcmp(name, "/private/var/mobile/Library/Caches") || strcmp(name, "/private/var/keybags") || strcmp(name, "/private/var/Keychains/keychain-2.db") || strcmp(name, "/private/var/Keychains/TrustStore.sqlite3") || strcmp(name, "/dev/disk0s1s1") || strcmp(name, "/dev/disk0s1s2") || strcmp(name, "/dev/disk4") /*need more testing*/ || strcmp(name, "/dev/tty.iap") /*need more testing*/))
        {
            return 1;
        }
    }
    //NotOpenable
    else
    {
        if(!(strcmp(name, "/") || strcmp(name, "/Developer") || strcmp(name, "/Library/Ringtones") || strcmp(name, "/usr/share") || strcmp(name, "/sbin/fsck_exfat") || strcmp(name, "/sbin/fsck_hfs") || strcmp(name, "/sbin/fsck_msdos") || strcmp(name, "/sbin/mount_hfs") || strcmp(name, "/sbin/newfs_hfs") || strcmp(name, "/usr/lib") || strcmp(name, "/System/Library/LaunchDaemons")))
        {
            return 1;
        }
        // /Applications different for versions
    }
    
    //Readable
    if( access( name, R_OK ) != -1 )
    {
        if(!(strcmp(name, "/Library") || strcmp(name, "/System") || strcmp(name, "/bin") || strcmp(name, "/cores") || strcmp(name, "/dev") || strcmp(name, "/etc") || strcmp(name, "/private") || strcmp(name, "/sbin") || strcmp(name, "/tmp") || strcmp(name, "/usr") || strcmp(name, "/var") || strcmp(name, "/var/mobile/Containers/Data/Application") || strcmp(name, "/var/mobile/Containers/Bundle/Application") || strcmp(name, "/var/containers/Bundle/Application") || strcmp(name, "/Library/Keychains") || strcmp(name, "/private/var/Keychains") || strcmp(name, "/private/var") || strcmp(name, "/etc/fstab") || strcmp(name, "/usr/bin") || strcmp(name, "/usr/sbin") || strcmp(name, "/Library/Wallpaper") || strcmp(name, "/usr/libexec") || strcmp(name, "/bin/df") || strcmp(name, "/bin/ps") || strcmp(name, "/sbin/fsck") || strcmp(name, "/sbin/fstyp") || strcmp(name, "/sbin/fstyp_hfs") || strcmp(name, "/sbin/launchd") || strcmp(name, "/sbin/mount") || strcmp(name, "/sbin/pfctl") || strcmp(name, "/usr/bin/brctl") || strcmp(name, "/usr/bin/powerlogHelperd") || strcmp(name, "/usr/bin/powerlogd") || strcmp(name, "/usr/bin/simulatecrash") || strcmp(name, "/usr/bin/sysdiagnose") || strcmp(name, "/usr/bin/taskinfo") || strcmp(name, "/usr/bin/vm_stat") || strcmp(name, "/usr/bin/zprint") || strcmp(name, "/usr/sbin/absd") || strcmp(name, "/usr/sbin/addNetworkInterface") || strcmp(name, "/usr/sbin/aslmanager") || strcmp(name, "/usr/sbin/BTAvrcp") || strcmp(name, "/usr/sbin/BTLEServer") || strcmp(name, "/usr/sbin/BTMap") || strcmp(name, "/usr/sbin/BTPbap") || strcmp(name, "/usr/sbin/BTServer") || strcmp(name, "/usr/sbin/BlueTool") || strcmp(name, "/usr/sbin/cfprefsd") || strcmp(name, "/usr/sbin/distnoted") || strcmp(name, "/usr/sbin/filecoordinationd") || strcmp(name, "/usr/sbin/ipconfig") || strcmp(name, "/usr/sbin/mDNSResponder") || strcmp(name, "/usr/sbin/mDNSResponderHelper") || strcmp(name, "/usr/sbin/mediaserverd") || strcmp(name, "/usr/sbin/notifyd") || strcmp(name, "/usr/sbin/nvram") || strcmp(name, "/usr/sbin/pppd") || strcmp(name, "/usr/sbin/racoon") || strcmp(name, "/usr/sbin/rtadvd") || strcmp(name, "/usr/sbin/scselect") || strcmp(name, "/usr/sbin/scutil") || strcmp(name, "/usr/sbin/spindump") || strcmp(name, "/usr/sbin/syslogd") || strcmp(name, "/usr/sbin/wifid") || strcmp(name, "/usr/sbin/wirelessproxd") || strcmp(name, "/usr/sbin/WirelessRadioManagerd") || strcmp(name, "/usr/libexec/BackupAgent") || strcmp(name, "/usr/libexec/BackupAgent2") || strcmp(name, "/usr/libexec/CrashHousekeeping") || strcmp(name, "/usr/libexec/DuetHeuristic-BM") || strcmp(name, "/usr/libexec/FSTaskScheduler") || strcmp(name, "/usr/libexec/FinishRestoreFromBackup") || strcmp(name, "/usr/libexec/MobileGestaltHelper") || strcmp(name, "/usr/libexec/NANDTaskScheduler") || strcmp(name, "/usr/libexec/OTAPKIAssetTool") || strcmp(name, "/usr/libexec/OTATaskingAgent") || strcmp(name, "/usr/libexec/PreboardService") || strcmp(name, "/usr/libexec/ProxiedCrashCopier") || strcmp(name, "/usr/libexec/PurpleReverseProxy") || strcmp(name, "/usr/libexec/SafariCloudHistoryPushAgent") || strcmp(name, "/usr/libexec/SyncAgent") || strcmp(name, "/usr/libexec/UserEventAgent") || strcmp(name, "/usr/libexec/adid") || strcmp(name, "/usr/libexec/afcd") || strcmp(name, "/usr/libexec/aitd") || strcmp(name, "/usr/libexec/amfid") || strcmp(name, "/usr/libexec/assertiond") || strcmp(name, "/usr/libexec/atc") || strcmp(name, "/usr/libexec/atwakeup") || strcmp(name, "/usr/libexec/backboardd") || strcmp(name, "/usr/libexec/biometrickitd") || strcmp(name, "/usr/libexec/bootpd")|| strcmp(name, "/usr/libexec/bubbled") || strcmp(name, "/usr/libexec/cc_fips_test") || strcmp(name, "/usr/libexec/checkpointd") || strcmp(name, "/usr/libexec/companion_proxy") || strcmp(name, "/usr/libexec/configd") || strcmp(name, "/usr/libexec/corecaptured") || strcmp(name, "/usr/libexec/coreduetd") || strcmp(name, "/usr/libexec/crash_mover") || strcmp(name, "/usr/libexec/demod") || strcmp(name, "/usr/libexec/demod_helper") || strcmp(name, "/usr/libexec/dhcpd") || strcmp(name, "/usr/libexec/diagnosticd") || strcmp(name, "/usr/libexec/duetexpertd") || strcmp(name, "/usr/libexec/findmydeviced") || strcmp(name, "/usr/libexec/fmfd") || strcmp(name, "/usr/libexec/fseventsd") || strcmp(name, "/usr/libexec/ftp-proxy") || strcmp(name, "/usr/libexec/gamecontrollerd") || strcmp(name, "/usr/libexec/gamed") || strcmp(name, "/usr/libexec/hangreporter") || strcmp(name, "/usr/libexec/hangtracerd") || strcmp(name, "/usr/libexec/hostapd") || strcmp(name, "/usr/libexec/idamd") || strcmp(name, "/usr/libexec/ifccd") || strcmp(name, "/usr/libexec/init_data_protection") || strcmp(name, "/usr/libexec/installd") || strcmp(name, "/usr/libexec/ioupsd") || strcmp(name, "/usr/libexec/keybagd") || strcmp(name, "/usr/libexec/languageassetd") || strcmp(name, "/usr/libexec/limitadtrackingd") || strcmp(name, "/usr/libexec/locationd") || strcmp(name, "/usr/libexec/lockbot") || strcmp(name, "/usr/libexec/lockdownd") || strcmp(name, "/usr/libexec/logd") || strcmp(name, "/usr/libexec/lsd") || strcmp(name, "/usr/libexec/lskdd") || strcmp(name, "/usr/libexec/lskdmsed") || strcmp(name, "/usr/libexec/mailq") || strcmp(name, "/usr/libexec/mc_mobile_tunnel") || strcmp(name, "/usr/libexec/misagent") || strcmp(name, "/usr/libexec/misd") || strcmp(name, "/usr/libexec/mmaintenanced") || strcmp(name, "/usr/libexec/mobile_assertion_agent") || strcmp(name, "/usr/libexec/mobile_diagnostics_relay") || strcmp(name, "/usr/libexec/mobile_ le_relay") || strcmp(name, "/usr/libexec/mobile_house_arrest") || strcmp(name, "/usr/libexec/mobile_installation_proxy") || strcmp(name, "/usr/libexec/mobile_obliterator") || strcmp(name, "/usr/libexec/mobile_storage_proxy") || strcmp(name, "/usr/libexec/mobileactivationd") || strcmp(name, "/usr/libexec/mobileassetd") || strcmp(name, "/usr/libexec/mtmergeprops") || strcmp(name, "/usr/libexec/neagent") || strcmp(name, "/usr/libexec/nehelper") || strcmp(name, "/usr/libexec/nesessionmanager") || strcmp(name, "/usr/libexec/nfcd") || strcmp(name, "/usr/libexec/nlcd") || strcmp(name, "/usr/libexec/notification_proxy") || strcmp(name, "/usr/libexec/nsurlsessiond") || strcmp(name, "/usr/libexec/nsurlstoraged") || strcmp(name, "/usr/libexec/online-auth-agent") || strcmp(name, "/usr/libexec/oscard") || strcmp(name, "/usr/libexec/pcapd") || strcmp(name, "/usr/libexec/pfd") || strcmp(name, "/usr/libexec/pipelined") || strcmp(name, "/usr/libexec/pkd") || strcmp(name, "/usr/libexec/pkreporter") || strcmp(name, "/usr/libexec/ptpd") || strcmp(name, "/usr/libexec/replayd") || strcmp(name, "/usr/libexec/rolld") || strcmp(name, "/usr/libexec/routined") || strcmp(name, "/usr/libexec/rtcreportingd") || strcmp(name, "/usr/libexec/securityd") || strcmp(name, "/usr/libexec/seld") || strcmp(name, "/usr/libexec/seputil") || strcmp(name, "/usr/libexec/sharingd") || strcmp(name, "/usr/libexec/splashboardd") || strcmp(name, "/usr/libexec/springboardservicesrelay") || strcmp(name, "/usr/libexec/streaming_zip_conduit") || strcmp(name, "/usr/libexec/swcd") || strcmp(name, "/usr/libexec/symptomsd") || strcmp(name, "/usr/libexec/symptomsd-helper") || strcmp(name, "/usr/libexec/syslog_relay") || strcmp(name, "/usr/libexec/sysstatuscheck") || strcmp(name, "/usr/libexec/timed") || strcmp(name, "/usr/libexec/tipsd") || strcmp(name, "/usr/libexec/transitd") || strcmp(name, "/usr/libexec/tzd") || strcmp(name, "/usr/libexec/tzinit") || strcmp(name, "/usr/libexec/tzlinkd") || strcmp(name, "/usr/libexec/wapic") || strcmp(name, "/usr/libexec/webinspectord") || strcmp(name, "/usr/libexec/wifiFirmwareLoader") || strcmp(name, "/usr/libexec/xpcproxy") || strcmp(name, "/Library/LaunchAgents") || strcmp(name, "/usr/libexec/aosnotifyd") || strcmp(name, "/usr/libexec/findmydeviced-nano-support") || strcmp(name, "/usr/libexec/ios_diagnostics_relay") || strcmp(name, "/usr/libexec/networkd") || strcmp(name, "/usr/libexec/networkd_privileged") || strcmp(name, "/usr/libexec/uuidpathd") || strcmp(name, "/private/var/root") || strcmp(name, "/private/var/mobile") || strcmp(name, "/private/var/mobile/Library") || strcmp(name, "/private/var/mobile/Library/Caches") || strcmp(name, "/private/var/keybags") || strcmp(name, "/private/var/Keychains/keychain-2.db") || strcmp(name, "/private/var/Keychains/TrustStore.sqlite3") || strcmp(name, "/dev/disk0s1s1") || strcmp(name, "/dev/disk0s1s2") || strcmp(name, "/dev/disk4") /*need more testing*/ || strcmp(name, "/dev/tty.iap") /*need more testing*/))
        {
            return 1;
        }
    }
    //NotReadable
    else
    {
        if(!(strcmp(name, "/") || strcmp(name, "/Developer") || strcmp(name, "/Library/Ringtones") || strcmp(name, "/usr/share") || strcmp(name, "/sbin/fsck_exfat") || strcmp(name, "/sbin/fsck_hfs") || strcmp(name, "/sbin/fsck_msdos") || strcmp(name, "/sbin/mount_hfs") || strcmp(name, "/sbin/newfs_hfs") || strcmp(name, "/usr/lib") || strcmp(name, "/System/Library/LaunchDaemons")))
        {
            return 1;
        }
        // /Applications different for versions
    }
    
    //Writeable
    if( access( name, W_OK ) != -1 )
    {
        //        if(!(strcmp(name, "/tmp") || strcmp(name, "/var/mobile/Containers/Data/Application") || strcmp(name, "/var/mobile/Containers/Bundle/Application") || strcmp(name, "/private/var/mobile") || strcmp(name, "/private/var/mobile/Library") || strcmp(name, "/private/var/mobile/Library/Caches")) || strstr(name, "/"))
        //        {
        // Nothing should be writable
        return 1;
        //        }
    }
    //NotWritable
    else
    {
        // Nothing is writable
    }
    
    //Executable
    if( access( name, X_OK ) != -1 )
    {
        if(!(strcmp(name, "/bin/df") || strcmp(name, "/bin/ps") || strcmp(name, "/sbin/fsck") || strcmp(name, "/sbin/fsck_exfat") || strcmp(name, "/sbin/fsck_hfs") || strcmp(name, "/sbin/fsck_msdos") || strcmp(name, "/sbin/fstyp") || strcmp(name, "/sbin/fstyp_hfs") || strcmp(name, "/sbin/launchd") || strcmp(name, "/sbin/mount") || strcmp(name, "/sbin/mount_hfs") || strcmp(name, "/sbin/newfs_hfs") || strcmp(name, "/sbin/pfctl") || strcmp(name, "/usr/bin/brctl") || strcmp(name, "/usr/bin/powerlogHelperd") || strcmp(name, "/usr/bin/powerlogd") || strcmp(name, "/usr/bin/simulatecrash") || strcmp(name, "/usr/bin/sysdiagnose") || strcmp(name, "/usr/bin/taskinfo") || strcmp(name, "/usr/bin/vm_stat") || strcmp(name, "/usr/bin/zprint") || strcmp(name, "/usr/sbin/absd") || strcmp(name, "/usr/sbin/addNetworkInterface") || strcmp(name, "/usr/sbin/aslmanager") || strcmp(name, "/usr/sbin/BTAvrcp") || strcmp(name, "/usr/sbin/BTLEServer") || strcmp(name, "/usr/sbin/BTMap") || strcmp(name, "/usr/sbin/BTPbap") || strcmp(name, "/usr/sbin/BTServer") || strcmp(name, "/usr/sbin/BlueTool") || strcmp(name, "/usr/sbin/cfprefsd") || strcmp(name, "/usr/sbin/distnoted") || strcmp(name, "/usr/sbin/filecoordinationd") || strcmp(name, "/usr/sbin/ipconfig") || strcmp(name, "/usr/sbin/mDNSResponder") || strcmp(name, "/usr/sbin/mDNSResponderHelper") || strcmp(name, "/usr/sbin/mediaserverd") || strcmp(name, "/usr/sbin/notifyd") || strcmp(name, "/usr/sbin/nvram") || strcmp(name, "/usr/sbin/pppd") || strcmp(name, "/usr/sbin/racoon") || strcmp(name, "/usr/sbin/rtadvd") || strcmp(name, "/usr/sbin/scselect") || strcmp(name, "/usr/sbin/scutil") || strcmp(name, "/usr/sbin/spindump") || strcmp(name, "/usr/sbin/syslogd") || strcmp(name, "/usr/sbin/wifid") || strcmp(name, "/usr/sbin/wirelessproxd") || strcmp(name, "/usr/sbin/WirelessRadioManagerd") || strcmp(name, "/usr/libexec/BackupAgent") || strcmp(name, "/usr/libexec/BackupAgent2") || strcmp(name, "/usr/libexec/CrashHousekeeping") || strcmp(name, "/usr/libexec/DuetHeuristic-BM") || strcmp(name, "/usr/libexec/FSTaskScheduler") || strcmp(name, "/usr/libexec/FinishRestoreFromBackup") || strcmp(name, "/usr/libexec/MobileGestaltHelper") || strcmp(name, "/usr/libexec/NANDTaskScheduler") || strcmp(name, "/usr/libexec/OTAPKIAssetTool") || strcmp(name, "/usr/libexec/OTATaskingAgent") || strcmp(name, "/usr/libexec/PreboardService") || strcmp(name, "/usr/libexec/ProxiedCrashCopier") || strcmp(name, "/usr/libexec/PurpleReverseProxy") || strcmp(name, "/usr/libexec/SafariCloudHistoryPushAgent") || strcmp(name, "/usr/libexec/SyncAgent") || strcmp(name, "/usr/libexec/UserEventAgent") || strcmp(name, "/usr/libexec/adid") || strcmp(name, "/usr/libexec/afcd") || strcmp(name, "/usr/libexec/aitd") || strcmp(name, "/usr/libexec/amfid") || strcmp(name, "/usr/libexec/assertiond") || strcmp(name, "/usr/libexec/atc") || strcmp(name, "/usr/libexec/atwakeup") || strcmp(name, "/usr/libexec/backboardd") || strcmp(name, "/usr/libexec/biometrickitd") || strcmp(name, "/usr/libexec/bootpd") || strcmp(name, "/usr/libexec/bubbled") || strcmp(name, "/usr/libexec/cc_fips_test") || strcmp(name, "/usr/libexec/checkpointd") || strcmp(name, "/usr/libexec/companion_proxy") || strcmp(name, "/usr/libexec/configd") || strcmp(name, "/usr/libexec/corecaptured") || strcmp(name, "/usr/libexec/coreduetd") || strcmp(name, "/usr/libexec/crash_mover") || strcmp(name, "/usr/libexec/demod") || strcmp(name, "/usr/libexec/demod_helper") || strcmp(name, "/usr/libexec/dhcpd") || strcmp(name, "/usr/libexec/diagnosticd") || strcmp(name, "/usr/libexec/duetexpertd") || strcmp(name, "/usr/libexec/findmydeviced") || strcmp(name, "/usr/libexec/fmfd") || strcmp(name, "/usr/libexec/fseventsd") || strcmp(name, "/usr/libexec/ftp-proxy") || strcmp(name, "/usr/libexec/gamecontrollerd") || strcmp(name, "/usr/libexec/gamed") || strcmp(name, "/usr/libexec/hangreporter") || strcmp(name, "/usr/libexec/hangtracerd") || strcmp(name, "/usr/libexec/hostapd") || strcmp(name, "/usr/libexec/idamd") || strcmp(name, "/usr/libexec/ifccd") || strcmp(name, "/usr/libexec/init_data_protection") || strcmp(name, "/usr/libexec/installd") || strcmp(name, "/usr/libexec/ioupsd") || strcmp(name, "/usr/libexec/keybagd") || strcmp(name, "/usr/libexec/languageassetd") || strcmp(name, "/usr/libexec/limitadtrackingd") || strcmp(name, "/usr/libexec/locationd") || strcmp(name, "/usr/libexec/lockbot") || strcmp(name, "/usr/libexec/lockdownd") || strcmp(name, "/usr/libexec/logd") || strcmp(name, "/usr/libexec/lsd") || strcmp(name, "/usr/libexec/lskdd") || strcmp(name, "/usr/libexec/lskdmsed") || strcmp(name, "/usr/libexec/mailq") || strcmp(name, "/usr/libexec/mc_mobile_tunnel") || strcmp(name, "/usr/libexec/misagent") || strcmp(name, "/usr/libexec/misd") || strcmp(name, "/usr/libexec/mmaintenanced") || strcmp(name, "/usr/libexec/mobile_assertion_agent") || strcmp(name, "/usr/libexec/mobile_diagnostics_relay") || strcmp(name, "/usr/libexec/mobile_ le_relay") || strcmp(name, "/usr/libexec/mobile_house_arrest") || strcmp(name, "/usr/libexec/mobile_installation_proxy") || strcmp(name, "/usr/libexec/mobile_obliterator") || strcmp(name, "/usr/libexec/mobile_storage_proxy") || strcmp(name, "/usr/libexec/mobileactivationd") || strcmp(name, "/usr/libexec/mobileassetd") || strcmp(name, "/usr/libexec/mtmergeprops") || strcmp(name, "/usr/libexec/neagent") || strcmp(name, "/usr/libexec/nehelper") || strcmp(name, "/usr/libexec/nesessionmanager") || strcmp(name, "/usr/libexec/nfcd") || strcmp(name, "/usr/libexec/nlcd") || strcmp(name, "/usr/libexec/notification_proxy") || strcmp(name, "/usr/libexec/nsurlsessiond") || strcmp(name, "/usr/libexec/nsurlstoraged") || strcmp(name, "/usr/libexec/online-auth-agent") || strcmp(name, "/usr/libexec/oscard") || strcmp(name, "/usr/libexec/pcapd") || strcmp(name, "/usr/libexec/pfd") || strcmp(name, "/usr/libexec/pipelined") || strcmp(name, "/usr/libexec/pkd") || strcmp(name, "/usr/libexec/pkreporter") || strcmp(name, "/usr/libexec/ptpd") || strcmp(name, "/usr/libexec/replayd") || strcmp(name, "/usr/libexec/rolld") || strcmp(name, "/usr/libexec/routined") || strcmp(name, "/usr/libexec/rtcreportingd") || strcmp(name, "/usr/libexec/securityd") || strcmp(name, "/usr/libexec/seld") || strcmp(name, "/usr/libexec/seputil") || strcmp(name, "/usr/libexec/sharingd") || strcmp(name, "/usr/libexec/splashboardd") || strcmp(name, "/usr/libexec/springboardservicesrelay") || strcmp(name, "/usr/libexec/streaming_zip_conduit") || strcmp(name, "/usr/libexec/swcd") || strcmp(name, "/usr/libexec/symptomsd") || strcmp(name, "/usr/libexec/symptomsd-helper") || strcmp(name, "/usr/libexec/syslog_relay") || strcmp(name, "/usr/libexec/sysstatuscheck") || strcmp(name, "/usr/libexec/timed") || strcmp(name, "/usr/libexec/tipsd") || strcmp(name, "/usr/libexec/transitd") || strcmp(name, "/usr/libexec/tzd") || strcmp(name, "/usr/libexec/tzinit") || strcmp(name, "/usr/libexec/tzlinkd") || strcmp(name, "/usr/libexec/wapic") || strcmp(name, "/usr/libexec/webinspectord") || strcmp(name, "/usr/libexec/wifiFirmwareLoader") || strcmp(name, "/usr/libexec/xpcproxy") || strcmp(name, "/usr/libexec/aosnotifyd") || strcmp(name, "/usr/libexec/findmydeviced-nano-support") || strcmp(name, "/usr/libexec/ios_diagnostics_relay") || strcmp(name, "/usr/libexec/networkd") || strcmp(name, "/usr/libexec/networkd_privileged") || strcmp(name, "/usr/libexec/uuidpathd") || strcmp(name, "/private/var/keybags") || strcmp(name, "/private/var/Keychains/keychain-2.db") || strcmp(name, "/private/var/Keychains/TrustStore.sqlite3") || strcmp(name, "/dev/disk0s1s1") || strcmp(name, "/dev/disk0s1s2") || strcmp(name, "/dev/disk4") || strcmp(name, "/etc/fstab") /*need more testing*/ || strcmp(name, "/dev/tty.iap") /*need more testing*/))
        {
            return 1;
        }
    }
    //NotExecutable
    else
    {
        if(!(strcmp(name, "/") || strcmp(name, "/Applications") || strcmp(name, "/Developer") || strcmp(name, "/Library") || strcmp(name, "/System") || strcmp(name, "/bin") || strcmp(name, "/cores") || strcmp(name, "/dev") || strcmp(name, "/etc") || strcmp(name, "/private") || strcmp(name, "/sbin") || strcmp(name, "/tmp") || strcmp(name, "/usr") || strcmp(name, "/var") || strcmp(name, "/var/mobile/Containers/Data/Application") || strcmp(name, "/var/mobile/Containers/Bundle/Application") || strcmp(name, "/var/containers/Bundle/Application") || strcmp(name, "/Library/Keychains") || strcmp(name, "/private/var/Keychains") || strcmp(name, "/private/var") || strcmp(name, "/usr/bin") || strcmp(name, "/usr/sbin") || strcmp(name, "/System") || strcmp(name, "/System") || strcmp(name, "/Library/Ringtones") || strcmp(name, "/Library/Wallpaper") || strcmp(name, "/usr/libexec") || strcmp(name, "/usr/share") || strcmp(name, "/usr/lib") || strcmp(name, "/Library/LaunchAgents") || strcmp(name, "/System/Library/LaunchDaemons") || strcmp(name, "/private/var/root") || strcmp(name, "/private/var/mobile") || strcmp(name, "/private/var/mobile/Library") || strcmp(name, "/private/var/mobile/Library/Caches")))
        {
            return 1;
        }
    }
    close(fd);
    return 0;
}

int checkFileStat(char* name)
{
    struct stat st;
    
    //Size
    if(lstat(name,&st) >= 0)
    {
        if(!(strcmp(name, "/")))
        {
            if(st.st_size > 748)
                return 1;
        }
//        if(!(strcmp(name, "/Developer")))
//        {
//            if(st.st_size != 340)
//                return 1;
//        }
 
        
        /*need more testing*/
        if(!(strcmp(name, "/dev/tty.iap")))
        {
            if(st.st_size == 0)
                return 1;
        }
        /*need more testing*/
        
        if(!(strcmp(name, "/bin")))
        {
            if(st.st_size > 136)
                return 1;
        }
        if(!(strcmp(name, "/cores") || strcmp(name, "/Library/LaunchAgents")))
        {
            if(st.st_size != 68)
                return 1;
        }
        if(!(strcmp(name, "/etc") || strcmp(name, "/var")))
        {
            if(st.st_size != 11)
                return 1;
        }
        if(!(strcmp(name, "/sbin") || strcmp(name, "/usr/share")))
        {
            if(st.st_size > 442)
                return 1;
        }
        if(!(strcmp(name, "/tmp")))
        {
            if(st.st_size != 15)
                return 1;
        }
        if(!(strcmp(name, "/private/var/keybags")))
        {
            if(st.st_size != 136)
                return 1;
        }
        if(!(strcmp(name, "/Library/Keychains") || strcmp(name, "/usr/libexec/aosnotifyd") || strcmp(name, "/usr/libexec/findmydeviced-nano-support") || strcmp(name, "/usr/libexec/ios_diagnostics_relay") || strcmp(name, "/usr/libexec/networkd") || strcmp(name, "/usr/libexec/networkd_privileged") || strcmp(name, "/usr/libexec/uuidpathd")))
        {
            if(st.st_size != 24)
                return 1;
        }
        if(!(strcmp(name, "/dev/disk0s1s1") || strcmp(name, "/dev/disk0s1s2") || strcmp(name, "/dev/disk4")))
        {
            if(st.st_size == 0)
                return 1;
        }
        if(!(strcmp(name, "/sbin/fsck_exfat") || strcmp(name, "/sbin/fsck_msdos")))
        {
            if(st.st_size != 66)
                return 1;
        }
        if(!(strcmp(name, "/sbin/fsck_hfs")))
        {
            if(st.st_size != 62)
                return 1;
        }
        if(!(strcmp(name, "/sbin/mount_hfs") || strcmp(name, "/sbin/newfs_hfs")))
        {
            if(st.st_size != 63)
                return 1;
        }
        if(!(strcmp(name, "/usr/libexec/init_data_protection")))
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
        if(!(strcmp(name, "/Applications") || strcmp(name, "/Library") || strcmp(name, "/Library/Ringtones") || strcmp(name, "/Library/Wallpaper")))
        {
            if(st.st_mode != 040775)
                return 1;
        }
        if(!(strcmp(name, "/Developer") || strcmp(name, "/cores")))
        {
            if(st.st_mode != 041775)
                return 1;
        }
        if(!(strcmp(name, "/System") || strcmp(name, "/bin") || strcmp(name, "/private") || strcmp(name, "/sbin") || strcmp(name, "/usr") || strcmp(name, "/var/mobile/Containers/Data/Application") || strcmp(name, "/var/mobile/Containers/Bundle/Application") || strcmp(name, "/var/containers/Bundle/Application") || strcmp(name, "/private/var/Keychains") || strcmp(name, "/private/var") || strcmp(name, "/usr/bin") || strcmp(name, "/usr/sbin") || strcmp(name, "/usr/libexec") || strcmp(name, "/usr/share") || strcmp(name, "/usr/lib")  || strcmp(name, "/Library/LaunchAgents") || strcmp(name, "/System/Library/LaunchDaemons") || strcmp(name, "/private/var/root")))
        {
            if(st.st_mode != 040755)
                return 1;
        }
        if(!(strcmp(name, "/dev")))
        {
            if(st.st_mode != 040555)
                return 1;
        }
        if(!(strcmp(name, "/private/var/mobile") || strcmp(name, "/private/var/mobile/Library")))
        {
            if(st.st_mode != 040711)
                return 1;
        }
        if(!(strcmp(name, "/etc") || strcmp(name, "/tmp") || strcmp(name, "/var") || strcmp(name, "/Library/Keychains") || strcmp(name, "/sbin/fsck_hfs") || strcmp(name, "/sbin/mount_hfs") || strcmp(name, "/sbin/newfs_hfs") || strcmp(name, "/usr/libexec/init_data_protection")))
        {
            if(st.st_mode != 0120755)
                return 1;
        }
        if(!(strcmp(name, "/private/var/keybags") || strcmp(name, "/private/var/mobile/Library/Caches")))
        {
            if(st.st_mode != 040700)
                return 1;
        }
        if(!(strcmp(name, "/private/var/Keychains/keychain-2.db") || strcmp(name, "/private/var/Keychains/TrustStore.sqlite3") || strcmp(name, "/dev/disk0s1s1") || strcmp(name, "/dev/disk0s1s2") || strcmp(name, "/dev/disk4") || strcmp(name, "/etc/fstab") || strcmp(name, "/bin/df") || strcmp(name, "/bin/ps") || strcmp(name, "/sbin/fsck") || strcmp(name, "/sbin/fstyp") || strcmp(name, "/sbin/fstyp_hfs") || strcmp(name, "/sbin/launchd") || strcmp(name, "/sbin/mount") || strcmp(name, "/sbin/pfctl") || strcmp(name, "/usr/bin/brctl") || strcmp(name, "/usr/bin/powerlogHelperd") || strcmp(name, "/usr/bin/powerlogd") || strcmp(name, "/usr/bin/simulatecrash") || strcmp(name, "/usr/bin/sysdiagnose") || strcmp(name, "/usr/bin/taskinfo") || strcmp(name, "/usr/bin/vm_stat") || strcmp(name, "/usr/bin/zprint") || strcmp(name, "/usr/sbin/absd") || strcmp(name, "/usr/sbin/addNetworkInterface") || strcmp(name, "/usr/sbin/aslmanager") || strcmp(name, "/usr/sbin/BTAvrcp") || strcmp(name, "/usr/sbin/BTLEServer") || strcmp(name, "/usr/sbin/BTMap") || strcmp(name, "/usr/sbin/BTPbap") || strcmp(name, "/usr/sbin/BTServer") || strcmp(name, "/usr/sbin/BlueTool") || strcmp(name, "/usr/sbin/cfprefsd") || strcmp(name, "/usr/sbin/distnoted") || strcmp(name, "/usr/sbin/filecoordinationd") || strcmp(name, "/usr/sbin/ipconfig") || strcmp(name, "/usr/sbin/mDNSResponder") || strcmp(name, "/usr/sbin/mDNSResponderHelper") || strcmp(name, "/usr/sbin/mediaserverd") || strcmp(name, "/usr/sbin/notifyd") || strcmp(name, "/usr/sbin/nvram") || strcmp(name, "/usr/sbin/pppd") || strcmp(name, "/usr/sbin/racoon") || strcmp(name, "/usr/sbin/rtadvd") || strcmp(name, "/usr/sbin/scselect") || strcmp(name, "/usr/sbin/scutil") || strcmp(name, "/usr/sbin/spindump") || strcmp(name, "/usr/sbin/syslogd") || strcmp(name, "/usr/sbin/wifid") || strcmp(name, "/usr/sbin/wirelessproxd") || strcmp(name, "/usr/sbin/WirelessRadioManagerd") || strcmp(name, "/usr/libexec/BackupAgent") || strcmp(name, "/usr/libexec/BackupAgent2") || strcmp(name, "/usr/libexec/CrashHousekeeping") || strcmp(name, "/usr/libexec/DuetHeuristic-BM") || strcmp(name, "/usr/libexec/FSTaskScheduler") || strcmp(name, "/usr/libexec/FinishRestoreFromBackup") || strcmp(name, "/usr/libexec/MobileGestaltHelper") || strcmp(name, "/usr/libexec/NANDTaskScheduler") || strcmp(name, "/usr/libexec/OTAPKIAssetTool") || strcmp(name, "/usr/libexec/OTATaskingAgent") || strcmp(name, "/usr/libexec/PreboardService") || strcmp(name, "/usr/libexec/ProxiedCrashCopier") || strcmp(name, "/usr/libexec/PurpleReverseProxy") || strcmp(name, "/usr/libexec/SafariCloudHistoryPushAgent") || strcmp(name, "/usr/libexec/SyncAgent") || strcmp(name, "/usr/libexec/UserEventAgent") || strcmp(name, "/usr/libexec/adid") || strcmp(name, "/usr/libexec/afcd") || strcmp(name, "/usr/libexec/aitd") || strcmp(name, "/usr/libexec/amfid") || strcmp(name, "/usr/libexec/assertiond") || strcmp(name, "/usr/libexec/atc") || strcmp(name, "/usr/libexec/atwakeup") || strcmp(name, "/usr/libexec/backboardd") || strcmp(name, "/usr/libexec/biometrickitd") || strcmp(name, "/usr/libexec/bootpd") || strcmp(name, "/usr/libexec/bubbled") || strcmp(name, "/usr/libexec/cc_fips_test") || strcmp(name, "/usr/libexec/checkpointd") || strcmp(name, "/usr/libexec/companion_proxy") || strcmp(name, "/usr/libexec/configd") || strcmp(name, "/usr/libexec/corecaptured") || strcmp(name, "/usr/libexec/coreduetd") || strcmp(name, "/usr/libexec/crash_mover") || strcmp(name, "/usr/libexec/demod") || strcmp(name, "/usr/libexec/demod_helper") || strcmp(name, "/usr/libexec/dhcpd") || strcmp(name, "/usr/libexec/diagnosticd") || strcmp(name, "/usr/libexec/duetexpertd") || strcmp(name, "/usr/libexec/findmydeviced") || strcmp(name, "/usr/libexec/fmfd") || strcmp(name, "/usr/libexec/fseventsd") || strcmp(name, "/usr/libexec/ftp-proxy") || strcmp(name, "/usr/libexec/gamecontrollerd") || strcmp(name, "/usr/libexec/gamed") || strcmp(name, "/usr/libexec/hangreporter") || strcmp(name, "/usr/libexec/hangtracerd") || strcmp(name, "/usr/libexec/hostapd") || strcmp(name, "/usr/libexec/idamd") || strcmp(name, "/usr/libexec/ifccd") || strcmp(name, "/usr/libexec/installd") || strcmp(name, "/usr/libexec/ioupsd") || strcmp(name, "/usr/libexec/keybagd") || strcmp(name, "/usr/libexec/languageassetd") || strcmp(name, "/usr/libexec/limitadtrackingd") || strcmp(name, "/usr/libexec/locationd") || strcmp(name, "/usr/libexec/lockbot") || strcmp(name, "/usr/libexec/lockdownd") || strcmp(name, "/usr/libexec/logd") || strcmp(name, "/usr/libexec/lsd") || strcmp(name, "/usr/libexec/lskdd") || strcmp(name, "/usr/libexec/lskdmsed") || strcmp(name, "/usr/libexec/mailq") || strcmp(name, "/usr/libexec/mc_mobile_tunnel") || strcmp(name, "/usr/libexec/misagent") || strcmp(name, "/usr/libexec/misd") || strcmp(name, "/usr/libexec/mmaintenanced") || strcmp(name, "/usr/libexec/mobile_assertion_agent") || strcmp(name, "/usr/libexec/mobile_diagnostics_relay") || strcmp(name, "/usr/libexec/mobile_file_relay") || strcmp(name, "/usr/libexec/mobile_house_arrest") || strcmp(name, "/usr/libexec/mobile_installation_proxy") || strcmp(name, "/usr/libexec/mobile_obliterator") || strcmp(name, "/usr/libexec/mobile_storage_proxy") || strcmp(name, "/usr/libexec/mobileactivationd") || strcmp(name, "/usr/libexec/mobileassetd") || strcmp(name, "/usr/libexec/mtmergeprops") || strcmp(name, "/usr/libexec/neagent") || strcmp(name, "/usr/libexec/nehelper") || strcmp(name, "/usr/libexec/nesessionmanager") || strcmp(name, "/usr/libexec/nfcd") || strcmp(name, "/usr/libexec/nlcd") || strcmp(name, "/usr/libexec/notification_proxy") || strcmp(name, "/usr/libexec/nsurlsessiond") || strcmp(name, "/usr/libexec/nsurlstoraged") || strcmp(name, "/usr/libexec/online-auth-agent") || strcmp(name, "/usr/libexec/oscard") || strcmp(name, "/usr/libexec/pcapd") || strcmp(name, "/usr/libexec/pfd") || strcmp(name, "/usr/libexec/pipelined") || strcmp(name, "/usr/libexec/pkd") || strcmp(name, "/usr/libexec/pkreporter") || strcmp(name, "/usr/libexec/ptpd") || strcmp(name, "/usr/libexec/replayd") || strcmp(name, "/usr/libexec/rolld") || strcmp(name, "/usr/libexec/routined") || strcmp(name, "/usr/libexec/rtcreportingd") || strcmp(name, "/usr/libexec/securityd") || strcmp(name, "/usr/libexec/seld") || strcmp(name, "/usr/libexec/seputil") || strcmp(name, "/usr/libexec/sharingd") || strcmp(name, "/usr/libexec/splashboardd") || strcmp(name, "/usr/libexec/springboardservicesrelay") || strcmp(name, "/usr/libexec/streaming_zip_conduit") || strcmp(name, "/usr/libexec/swcd") || strcmp(name, "/usr/libexec/symptomsd") || strcmp(name, "/usr/libexec/symptomsd-helper") || strcmp(name, "/usr/libexec/syslog_relay") || strcmp(name, "/usr/libexec/sysstatuscheck") || strcmp(name, "/usr/libexec/timed") || strcmp(name, "/usr/libexec/tipsd") || strcmp(name, "/usr/libexec/transitd") || strcmp(name, "/usr/libexec/tzd") || strcmp(name, "/usr/libexec/tzinit") || strcmp(name, "/usr/libexec/tzlinkd") || strcmp(name, "/usr/libexec/wapic") || strcmp(name, "/usr/libexec/webinspectord") || strcmp(name, "/usr/libexec/wifiFirmwareLoader") || strcmp(name, "/usr/libexec/xpcproxy") || strcmp(name, "/usr/libexec/aosnotifyd") || strcmp(name, "/usr/libexec/findmydeviced-nano-support") || strcmp(name, "/usr/libexec/ios_diagnostics_relay") || strcmp(name, "/usr/libexec/networkd") || strcmp(name, "/usr/libexec/networkd_privileged") || strcmp(name, "/usr/libexec/uuidpathd") /*need more testing*/ || strcmp(name, "/dev/tty.iap") /*need more testing*/))
        {
            if(st.st_mode != 01)
                return 1;
        }
        if(!(strcmp(name, "/sbin/fsck_exfat") || strcmp(name, "/sbin/fsck_msdos")))
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
