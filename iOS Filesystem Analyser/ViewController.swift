//
//  ViewController.swift
//
//  Created by abhinash jain on 22/06/16.
//  Copyright © 2016 abhinash jain. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {

        //  9911BB38-F418-45EB-8A90-A7A2DCA67FE9, BBEACC3F-EE3F-4D6E-B2B9-FC33B2FBF38C, E3C434C8-A262-4714-BE57-687D2479F7FB are GUIDs of some random app
        
        let obj_name = ["/", "/Applications", "/Developer", "/Library", "/System", "/User", "/bin", "/boot", "/cores", "/dev", "/etc", "/lib", "/mnt", "/private", "/sbin", "/tmp", "/usr", "/var", "/var/mobile/Containers/Data/Application", "/var/mobile/Containers/Data/Application/9911BB38-F418-45EB-8A90-A7A2DCA67FE9", "/var/mobile/Containers/Bundle/Application", "/var/mobile/Containers/Bundle/Application/BBEACC3F-EE3F-4D6E-B2B9-FC33B2FBF38C", "/var/containers/Bundle/Application", "/var/containers/Bundle/Application/E3C434C8-A262-4714-BE57-687D2479F7FB", "/private/var/keybags", "/Library/Keychains", "/private/var/Keychains", "/private/var/Keychains/keychain-2.db", "/private/var/Keychains/TrustStore.sqlite3", "/private/var", "/dev/disk0s1s1", "/dev/disk0s1s2", "/dev/disk4", "/etc/fstab", "/usr/bin", "/usr/sbin", "/Library/Ringtones", "/Library/Wallpaper", "/usr/libexec", "/usr/share", "/bin/df", "/bin/ps", "/sbin/fsck", "/sbin/fsck_exfat", "/sbin/fsck_hfs", "/sbin/fsck_msdos", "/sbin/fstyp", "/sbin/fstyp_hfs", "/sbin/launchd", "/sbin/mount", "/sbin/mount_hfs", "/sbin/newfs_hfs", "/sbin/pfctl", "/usr/bin/brctl", "/usr/bin/powerlogHelperd", "/usr/bin/powerlogd", "/usr/bin/simulatecrash", "/usr/bin/sysdiagnose", "/usr/bin/taskinfo", "/usr/bin/vm_stat", "/usr/bin/zprint", "/usr/sbin/absd", "/usr/sbin/addNetworkInterface", "/usr/sbin/aslmanager", "/usr/sbin/BTAvrcp", "/usr/sbin/BTLEServer", "/usr/sbin/BTMap", "/usr/sbin/BTPbap", "/usr/sbin/BTServer", "/usr/sbin/BlueTool", "/usr/sbin/cfprefsd", "/usr/sbin/distnoted", "/usr/sbin/filecoordinationd", "/usr/sbin/ipconfig", "/usr/sbin/mDNSResponder", "/usr/sbin/mDNSResponderHelper", "/usr/sbin/mediaserverd", "/usr/sbin/notifyd", "/usr/sbin/nvram", "/usr/sbin/pppd", "/usr/sbin/racoon", "/usr/sbin/rtadvd", "/usr/sbin/scselect", "/usr/sbin/scutil", "/usr/sbin/spindump", "/usr/sbin/syslogd", "/usr/sbin/wifid", "/usr/sbin/wirelessproxd", "/usr/sbin/WirelessRadioManagerd", "/usr/libexec/BackupAgent", "/usr/libexec/BackupAgent2", "/usr/libexec/CrashHousekeeping", "/usr/libexec/DuetHeuristic-BM", "/usr/libexec/FSTaskScheduler", "/usr/libexec/FinishRestoreFromBackup", "/usr/libexec/MobileGestaltHelper", "/usr/libexec/NANDTaskScheduler", "/usr/libexec/OTAPKIAssetTool", "/usr/libexec/OTATaskingAgent", "/usr/libexec/PreboardService", "/usr/libexec/ProxiedCrashCopier", "/usr/libexec/PurpleReverseProxy", "/usr/libexec/SafariCloudHistoryPushAgent", "/usr/libexec/SyncAgent", "/usr/libexec/UserEventAgent", "/usr/libexec/adid", "/usr/libexec/afcd", "/usr/libexec/aitd", "/usr/libexec/amfid", "/usr/libexec/assertiond", "/usr/libexec/atc", "/usr/libexec/atwakeup", "/usr/libexec/backboardd", "/usr/libexec/biometrickitd", "/usr/libexec/bootpd", "/usr/libexec/bubbled", "/usr/libexec/cc_fips_test", "/usr/libexec/checkpointd", "/usr/libexec/companion_proxy", "/usr/libexec/configd", "/usr/libexec/corecaptured", "/usr/libexec/coreduetd", "/usr/libexec/crash_mover", "/usr/libexec/demod", "/usr/libexec/demod_helper", "/usr/libexec/dhcpd", "/usr/libexec/diagnosticd", "/usr/libexec/duetexpertd", "/usr/libexec/findmydeviced", "/usr/libexec/fmfd", "/usr/libexec/fseventsd", "/usr/libexec/ftp-proxy", "/usr/libexec/gamecontrollerd", "/usr/libexec/gamed", "/usr/libexec/hangreporter", "/usr/libexec/hangtracerd", "/usr/libexec/hostapd", "/usr/libexec/idamd", "/usr/libexec/ifccd", "/usr/libexec/init_data_protection", "/usr/libexec/installd", "/usr/libexec/ioupsd", "/usr/libexec/keybagd", "/usr/libexec/languageassetd", "/usr/libexec/limitadtrackingd", "/usr/libexec/locationd", "/usr/libexec/lockbot", "/usr/libexec/lockdownd", "/usr/libexec/logd", "/usr/libexec/lsd", "/usr/libexec/lskdd", "/usr/libexec/lskdmsed", "/usr/libexec/mailq", "/usr/libexec/mc_mobile_tunnel", "/usr/libexec/misagent", "/usr/libexec/misd", "/usr/libexec/mmaintenanced", "/usr/libexec/mobile_assertion_agent", "/usr/libexec/mobile_diagnostics_relay", "/usr/libexec/mobile_file_relay", "/usr/libexec/mobile_house_arrest", "/usr/libexec/mobile_installation_proxy", "/usr/libexec/mobile_obliterator", "/usr/libexec/mobile_storage_proxy", "/usr/libexec/mobileactivationd", "/usr/libexec/mobileassetd", "/usr/libexec/mtmergeprops", "/usr/libexec/neagent", "/usr/libexec/nehelper", "/usr/libexec/nesessionmanager", "/usr/libexec/nfcd", "/usr/libexec/nlcd", "/usr/libexec/notification_proxy", "/usr/libexec/nsurlsessiond", "/usr/libexec/nsurlstoraged", "/usr/libexec/online-auth-agent", "/usr/libexec/oscard", "/usr/libexec/pcapd", "/usr/libexec/pfd", "/usr/libexec/pipelined", "/usr/libexec/pkd", "/usr/libexec/pkreporter", "/usr/libexec/ptpd", "/usr/libexec/replayd", "/usr/libexec/rolld", "/usr/libexec/routined", "/usr/libexec/rtcreportingd", "/usr/libexec/securityd", "/usr/libexec/seld", "/usr/libexec/seputil", "/usr/libexec/sharingd", "/usr/libexec/splashboardd", "/usr/libexec/springboardservicesrelay", "/usr/libexec/streaming_zip_conduit", "/usr/libexec/swcd", "/usr/libexec/symptomsd", "/usr/libexec/symptomsd-helper", "/usr/libexec/syslog_relay", "/usr/libexec/sysstatuscheck", "/usr/libexec/timed", "/usr/libexec/tipsd", "/usr/libexec/transitd", "/usr/libexec/tzd", "/usr/libexec/tzinit", "/usr/libexec/tzlinkd", "/usr/libexec/wapic", "/usr/libexec/webinspectord", "/usr/libexec/wifiFirmwareLoader", "/usr/libexec/xpcproxy", "/usr/lib", "/Library/LaunchAgents", "/System/Library/LaunchDaemons", "/usr/sbin/fairplayd.A2", "/usr/libexec/aosnotifyd", "/usr/libexec/findmydeviced-nano-support", "/usr/libexec/ios_diagnostics_relay", "/usr/libexec/networkd", "/usr/libexec/networkd_privileged", "/usr/libexec/uuidpathd", "/private/var/root", "/private/var/mobile", "/private/var/mobile/Library", "/private/var/mobile/Library/Caches", "/private/var/stash", "/private/var/lib/cydia", "/private/var/tmp/cydia.log", "/private/var/tmp/pgloader", "/private/var/mobile/Library/Caches/com.saurik.Cydia", "/private/var/mobile/Library/Cydia", "/private/var/mobile/Library/SBSettings", "/private/var/mobile/Library/SBSettings/Themes", "/var/tmp/pgloader", "/var/log/syslog", "/var/lib/cydia", "/var/cache/apt", "/private/var/lib/apt", "/User/Applications", "/usr/arm-apple-darwin9", "/usr/include", "/etc/apt", "/etc/ssh/sshd_config", "/usr/libexec/ssh-keysign", "/var/tmp/cydia.log", "/usr/lib/libpatcyh.dylib", "/usr/lib/librocketbootstrap.dylib", "/usr/lib/libapplist.dylib", "/Library/MobileSubstrate/DynamicLibraries", "/Library/MobileSubstrate/DynamicLibraries/AppList.dylib", "/Library/MobileSubstrate/DynamicLibraries/AppList.plist", "/Library/MobileSubstrate/DynamicLibraries/CustomWidgetIcons.dylib", "/Library/MobileSubstrate/DynamicLibraries/CustomWidgetIcons.plist", "/Library/MobileSubstrate/DynamicLibraries/MobileSafety.dylib", "/Library/MobileSubstrate/DynamicLibraries/MobileSafety.plist", "/Library/MobileSubstrate/DynamicLibraries/OpenSiri.dylib", "/Library/MobileSubstrate/DynamicLibraries/OpenSiri.plist", "/Library/MobileSubstrate/DynamicLibraries/PreferenceLoader.dylib", "/Library/MobileSubstrate/DynamicLibraries/PreferenceLoader.plist", "/Library/MobileSubstrate/DynamicLibraries/RocketBootstrap.dylib", "/Library/MobileSubstrate/DynamicLibraries/RocketBootstrap.plist", "/Library/MobileSubstrate/DynamicLibraries/SSLKillSwitch2.dylib", "/Library/MobileSubstrate/DynamicLibraries/SSLKillSwitch2.plist", "/Library/MobileSubstrate/DynamicLibraries/WeeLoader.dylib", "/Library/MobileSubstrate/DynamicLibraries/WeeLoader.plist", "/Library/MobileSubstrate/DynamicLibraries/patcyh.dylib", "/Library/MobileSubstrate/DynamicLibraries/patcyh.plist", "/Library/MobileSubstrate/MobileSubstrate.dylib", "/Library/Frameworks/CydiaSubstrate.framework", "/Library/Frameworks/CydiaSubstrate.framework/Libraries/SubstrateInjection.dylib", "/Library/MobileSubstrate/DynamicLibraries/Veency.plist", "/Library/MobileSubstrate/DynamicLibraries/LiveClock.plist", "/System/Library/LaunchDaemons/com.ikey.bbot.plist", "/System/Library/LaunchDaemons/com.saurik.Cydia.Startup.plist", "/var/lib/apt", "/usr/libexec/sftp-server", "/Applications/Cydia.app", "/Applications/RockApp.app", "/Applications/Icy.app", "/Applications/WinterBoard.app", "/Applications/SBSettings.app", "/Applications/MxTube.app", "/Applications/IntelliScreen.app", "/Applications/FakeCarrier.app", "/Applications/blackra1n.app", "/bin/bash", "/bin/bunzip2", "/bin/bzcat", "/bin/bzip2", "/bin/bzip2recover", "/bin/cat", "/bin/chgrp", "/bin/chmod", "/bin/chown", "/bin/cp", "/bin/date", "/bin/dd", "/bin/dir", "/bin/echo", "/bin/egrep", "/bin/false", "/bin/fgrep", "/bin/grep", "/bin/gzexe", "/bin/gzip", "/bin/kill", "/bin/launchctl", "/bin/ln", "/bin/ls", "/bin/mkdir", "/bin/mknod", "/bin/mktemp", "/bin/more", "/bin/mv", "/bin/ping", "/bin/ping6", "/bin/pwd", "/bin/readlink", "/bin/rm", "/bin/rmdir", "/bin/run-parts", "/bin/sed", "/bin/sh", "/bin/sleep", "/bin/stty", "/bin/su", "/bin/sync", "/bin/tar", "/bin/touch", "/bin/true", "/bin/uname", "/bin/uncompress", "/bin/vdir", "/bin/zcat", "/bin/zcmp", "/bin/zdiff", "/bin/zegrep", "/bin/zfgrep", "/bin/zforce", "/bin/zgrep", "/bin/zless", "/bin/zmore", "/bin/znew", "/sbin/clri", "/sbin/dmesg", "/sbin/dump", "/sbin/dumpfs", "/sbin/dynamic_pager", "/sbin/fstyp_msdos", "/sbin/fstyp_ntfs", "/sbin/fstyp_udf", "/sbin/fstyp_ufs", "/sbin/halt", "/sbin/ifconfig", "/sbin/ip6fw", "/sbin/ipfw", "/sbin/mount_cd9660", "/sbin/mount_devfs", "/sbin/mount_fdesc", "/sbin/mount_kernfs", "/sbin/mount_null", "/sbin/mount_procfs", "/sbin/mount_synthfs", "/sbin/mount_union", "/sbin/netstat", "/sbin/newfs", "/sbin/nologin", "/sbin/ping", "/sbin/ping6", "/sbin/quotacheck", "/sbin/reboot", "/sbin/restore", "/sbin/route", "/sbin/routed", "/sbin/rtsol", "/sbin/slattach", "/sbin/tunefs", "/sbin/umount", "/usr/bin/2html", "/usr/bin/2xml", "/usr/bin/7z", "/usr/bin/7za", "/usr/bin/Clutch", "/usr/bin/Clutch2", "/usr/bin/FileDP", "/usr/bin/ObjectDump", "/usr/bin/[", "/usr/bin/appsearch", "/usr/bin/apr-1-config", "/usr/bin/apt-cache", "/usr/bin/apt-cdrom", "/usr/bin/apt-config", "/usr/bin/apt-extracttemplates", "/usr/bin/apt-ftparchive", "/usr/bin/apt-get", "/usr/bin/apt-key", "/usr/bin/apt-mark", "/usr/bin/apt-sortpkgs", "/usr/bin/apu-1-config", "/usr/bin/ar", "/usr/bin/arch", "/usr/bin/as", "/usr/bin/autopoint", "/usr/bin/awk", "/usr/bin/base64", "/usr/bin/basename", "/usr/bin/bashbug", "/usr/bin/bitcode_strip", "/usr/bin/c_rehash", "/usr/bin/captoinfo", "/usr/bin/cfversion", "/usr/bin/chcon", "/usr/bin/checksyms", "/usr/bin/chflags", "/usr/bin/chfn", "/usr/bin/chown", "/usr/bin/chsh", "/usr/bin/cksum", "/usr/bin/class-dump", "/usr/bin/class-dump-z", "/usr/bin/classdump-dyld", "/usr/bin/clear", "/usr/bin/cmp", "/usr/bin/codesign_allocate", "/usr/bin/comm", "/usr/bin/compress", "/usr/bin/csplit", "/usr/bin/csv2", "/usr/bin/ctags", "/usr/bin/curl", "/usr/bin/curl-config", "/usr/bin/cut", "/usr/bin/cycc", "/usr/bin/cycript", "/usr/bin/cynject", "/usr/bin/db_archive", "/usr/bin/db_checkpoint", "/usr/bin/db_codegen", "/usr/bin/db_deadlock", "/usr/bin/db_dump", "/usr/bin/db_hotbackup", "/usr/bin/db_load", "/usr/bin/db_printlog", "/usr/bin/db_recover", "/usr/bin/db_stat", "/usr/bin/db_upgrade", "/usr/bin/db_verify", "/usr/bin/deviceinfo", "/usr/bin/df", "/usr/bin/diff", "/usr/bin/diff3", "/usr/bin/dircolors", "/usr/bin/dirname", "/usr/bin/doNotify", "/usr/bin/dpkg", "/usr/bin/dpkg-deb", "/usr/bin/dpkg-name", "/usr/bin/dpkg-query", "/usr/bin/dpkg-split", "/usr/bin/dpkg-trigger", "/usr/bin/dselect", "/usr/bin/dsymutil", "/usr/bin/du", "/usr/bin/dyldinfo", "/usr/bin/env", "/usr/bin/envsubst", "/usr/bin/error", "/usr/bin/ex", "/usr/bin/expand", "/usr/bin/expr", "/usr/bin/factor", "/usr/bin/faker", "/usr/bin/filan", "/usr/bin/find", "/usr/bin/finger", "/usr/bin/fmt", "/usr/bin/fold", "/usr/bin/fsmon", "/usr/bin/ftp", "/usr/bin/funzip", "/usr/bin/gawk", "/usr/bin/gdb", "/usr/bin/getconf", "/usr/bin/gettext", "/usr/bin/gettext.sh", "/usr/bin/gettextize", "/usr/bin/getty", "/usr/bin/git", "/usr/bin/git-cvsserver", "/usr/bin/git-receive-pack", "/usr/bin/git-shell", "/usr/bin/git-upload-archive", "/usr/bin/git-upload-pack", "/usr/bin/gpg", "/usr/bin/gpg-zip", "/usr/bin/gpgsplit", "/usr/bin/gpgv", "/usr/bin/groups", "/usr/bin/gssc", "/usr/bin/head", "/usr/bin/hexdump", "/usr/bin/hostid", "/usr/bin/hostinfo", "/usr/bin/hostname", "/usr/bin/html2", "/usr/bin/id", "/usr/bin/igawk", "/usr/bin/indr", "/usr/bin/infocmp", "/usr/bin/infotocap", "/usr/bin/install", "/usr/bin/install_name_tool", "/usr/bin/installipa", "/usr/bin/iomfsetgamma", "/usr/bin/ip-print", "/usr/bin/ip6conf", "/usr/bin/ipainstaller", "/usr/bin/ipcrm", "/usr/bin/ipcs", "/usr/bin/join", "/usr/bin/keychain_dumper", "/usr/bin/keychaineditor", "/usr/bin/killall", "/usr/bin/last", "/usr/bin/ld", "/usr/bin/ldid", "/usr/bin/ldrestart", "/usr/bin/less", "/usr/bin/lessecho", "/usr/bin/lesskey", "/usr/bin/libtool", "/usr/bin/link", "/usr/bin/lipo", "/usr/bin/locale", "/usr/bin/locate", "/usr/bin/logger", "/usr/bin/login", "/usr/bin/logname", "/usr/bin/lsof", "/usr/bin/lsvfs", "/usr/bin/lzcat", "/usr/bin/lzcmp", "/usr/bin/lzdiff", "/usr/bin/lzegrep", "/usr/bin/lzfgrep", "/usr/bin/lzgrep", "/usr/bin/lzless", "/usr/bin/lzma", "/usr/bin/lzmadec", "/usr/bin/lzmainfo", "/usr/bin/lzmore", "/usr/bin/machocheck", "/usr/bin/make", "/usr/bin/md", "/usr/bin/md5sum", "/usr/bin/mesg", "/usr/bin/mig", "/usr/bin/mkfifo", "/usr/bin/mktemp", "/usr/bin/more", "/usr/bin/msgattrib", "/usr/bin/msgcat", "/usr/bin/msgcmp", "/usr/bin/msgcomm", "/usr/bin/msgconv", "/usr/bin/msgen", "/usr/bin/msgexec", "/usr/bin/msgfilter", "/usr/bin/msgfmt", "/usr/bin/msggrep", "/usr/bin/msginit", "/usr/bin/msgmerge", "/usr/bin/msgunfmt", "/usr/bin/msguniq", "/usr/bin/nano", "/usr/bin/ncurses5-config", "/usr/bin/ncursesw5-config", "/usr/bin/neon-config", "/usr/bin/ngettext", "/usr/bin/nice", "/usr/bin/nl", "/usr/bin/nm", "/usr/bin/nmedit", "/usr/bin/nohup", "/usr/bin/notificationWatcher", "/usr/bin/nproc", "/usr/bin/od", "/usr/bin/ondeviceconsole", "/usr/bin/open", "/usr/bin/openURL", "/usr/bin/openssl", "/usr/bin/otool", "/usr/bin/pagesize", "/usr/bin/pagestuff", "/usr/bin/passwd", "/usr/bin/paste", "/usr/bin/patch", "/usr/bin/pathchk", "/usr/bin/pax", "/usr/bin/pbcopy", "/usr/bin/pbpaste", "/usr/bin/pbwatcher", "/usr/bin/pcap-config", "/usr/bin/pcre-config", "/usr/bin/pcregrep", "/usr/bin/pcretest", "/usr/bin/pincrush", "/usr/bin/ping", "/usr/bin/pinky", "/usr/bin/play", "/usr/bin/plutil", "/usr/bin/pr", "/usr/bin/printenv", "/usr/bin/printf", "/usr/bin/procan", "/usr/bin/ps", "/usr/bin/ptx", "/usr/bin/quota", "/usr/bin/ranlib", "/usr/bin/rcp", "/usr/bin/recode-sr-latin", "/usr/bin/redo_prebinding", "/usr/bin/renice", "/usr/bin/reset", "/usr/bin/restart", "/usr/bin/rlogin", "/usr/bin/rnano", "/usr/bin/rpcgen", "/usr/bin/rsh", "/usr/bin/rsync", "/usr/bin/runcon", "/usr/bin/rview", "/usr/bin/rvim", "/usr/bin/say", "/usr/bin/sbdidlaunch", "/usr/bin/sbreload", "/usr/bin/scp", "/usr/bin/script", "/usr/bin/sdiff", "/usr/bin/seg_addr_table", "/usr/bin/seg_hack", "/usr/bin/segedit", "/usr/bin/seq", "/usr/bin/sftp", "/usr/bin/sha1sum", "/usr/bin/sha224sum", "/usr/bin/sha256sum", "/usr/bin/sha384sum", "/usr/bin/sha512sum", "/usr/bin/shred", "/usr/bin/shuf", "/usr/bin/size", "/usr/bin/slogin", "/usr/bin/socat", "/usr/bin/sort", "/usr/bin/split", "/usr/bin/sqlite3", "/usr/bin/ssh", "/usr/bin/ssh-add", "/usr/bin/ssh-agent", "/usr/bin/ssh-keygen", "/usr/bin/ssh-keyscan", "/usr/bin/stat", "/usr/bin/strings", "/usr/bin/strip", "/usr/bin/sudo", "/usr/bin/sudoedit", "/usr/bin/sum", "/usr/bin/svn", "/usr/bin/svnadmin", "/usr/bin/svndumpfilter", "/usr/bin/svnlook", "/usr/bin/svnserve", "/usr/bin/svnsync", "/usr/bin/svnversion", "/usr/bin/sw_vers", "/usr/bin/syslogoff", "/usr/bin/syslogon", "/usr/bin/tabs", "/usr/bin/tac", "/usr/bin/tail", "/usr/bin/talk", "/usr/bin/tar", "/usr/bin/tee", "/usr/bin/telnet", "/usr/bin/test", "/usr/bin/tftp", "/usr/bin/tic", "/usr/bin/time", "/usr/bin/timeout", "/usr/bin/toe", "/usr/bin/top", "/usr/bin/tput", "/usr/bin/tr", "/usr/bin/truncate", "/usr/bin/tset", "/usr/bin/tsort", "/usr/bin/tty", "/usr/bin/uicache", "/usr/bin/uiduid", "/usr/bin/uiopen", "/usr/bin/unexpand", "/usr/bin/unifdef", "/usr/bin/uniq", "/usr/bin/unlink", "/usr/bin/unlzma", "/usr/bin/unrar", "/usr/bin/unwinddump", "/usr/bin/unzip", "/usr/bin/unzipsfx", "/usr/bin/updatedb", "/usr/bin/uptime", "/usr/bin/urlclip", "/usr/bin/users", "/usr/bin/uudecode", "/usr/bin/uuencode", "/usr/bin/uuid", "/usr/bin/uuid-config", "/usr/bin/view", "/usr/bin/vim", "/usr/bin/vimdiff", "/usr/bin/vimtutor", "/usr/bin/wc", "/usr/bin/wget", "/usr/bin/which", "/usr/bin/who", "/usr/bin/whoami", "/usr/bin/whois", "/usr/bin/write", "/usr/bin/xar", "/usr/bin/xargs", "/usr/bin/xgettext", "/usr/bin/xml2", "/usr/bin/xml2-config", "/usr/bin/xmlcatalog", "/usr/bin/xmllint", "/usr/bin/xmlwf", "/usr/bin/xxd", "/usr/bin/yes", "/usr/bin/zip", "/usr/bin/zipcloak", "/usr/bin/zipnote", "/usr/bin/zipsplit", "/usr/sbin/ac", "/usr/sbin/accton", "/usr/sbin/arp", "/usr/sbin/chown", "/usr/sbin/chroot", "/usr/sbin/dev_mkdb", "/usr/sbin/edquota", "/usr/sbin/fdisk", "/usr/sbin/frida-server", "/usr/sbin/ioalloccount", "/usr/sbin/ioclasscount", "/usr/sbin/ioreg", "/usr/sbin/iostat", "/usr/sbin/mkfile", "/usr/sbin/natd", "/usr/sbin/ndp", "/usr/sbin/pwd_mkdb", "/usr/sbin/quot", "/usr/sbin/quotaon", "/usr/sbin/repquota", "/usr/sbin/sshd", "/usr/sbin/startupfiletool", "/usr/sbin/sysctl", "/usr/sbin/tcpdump", "/usr/sbin/traceroute", "/usr/sbin/traceroute6", "/usr/sbin/trpt", "/usr/sbin/update", "/usr/sbin/vifs", "/usr/sbin/vipw", "/usr/sbin/visudo", "/usr/sbin/vsdbutil", "/usr/sbin/zdump", "/usr/sbin/zic", "/usr/libexec/MSUnrestrictProcess", "/usr/libexec/as", "/usr/libexec/awk", "/usr/libexec/bigram", "/usr/libexec/code", "/usr/libexec/cydia", "/usr/libexec/fingerd", "/usr/libexec/frcode", "/usr/libexec/ftpd", "/usr/libexec/gdb", "/usr/libexec/git-core", "/usr/libexec/gnupg", "/usr/libexec/inetd", "/usr/libexec/kdumpd", "/usr/libexec/logind", "/usr/libexec/migcom", "/usr/libexec/rexecd", "/usr/libexec/rlogind", "/usr/libexec/rmt", "/usr/libexec/rocketd", "/usr/libexec/rshd", "/usr/libexec/ssh-pkcs11-helper", "/usr/libexec/sshd-keygen-wrapper", "/usr/libexec/studentd", "/usr/libexec/substrate", "/usr/libexec/sudo_noexec.dylib", "/usr/libexec/sudo_noexec.la", "/usr/libexec/telnetd", "/usr/libexec/tftpd", "/usr/libexec/uucpd", "/usr/libexec/vndevice", "/.cydia_no_stash", "/etc/ssh", "/usr/local/bin", "/usr/local/bin/CSStashedAppExecutable", "/Library/MobileSubstrate", "/Library/LaunchDaemons", "/Library/LaunchDaemons/com.openssh.sshd.plist", "/Library/LaunchDaemons/com.rpetrich.rocketbootstrapd.plist", "/Library/LaunchDaemons/com.saurik.Cydia.Startup.plist", "/Library/LaunchDaemons/io.pangu93.loader.plist", "/Library/LaunchDaemons/re.frida.server.plist", "/System/Library/LaunchAgents", "/System/Library/LaunchDaemons/com.bigboss.sbsettingsd.plist", "/usr/bin/chpass", "/usr/lib/libcycript.0.dylib", "/usr/lib/libcycript.cy", "/usr/lib/libcycript.db", "/usr/lib/libcycript.dylib", "/usr/lib/libcycript.jar", "/var/stash", "/var/stash/usrbin", "/var/stash/usrlib", "/var/stash/usrlib/libcycript.cy", "/var/stash/usrlib/libcycript.db", "/var/stash/usrlib/libcycript.dylib", "/var/stash/usrlib/libcycript.jar", "/var/db/stash", "/Applications/Terminal.app", /*need more testing*/ "/dev/tty.iap" /*need more testing*/]

        for i in obj_name
        {
            let name: [CChar]? = i.cString(using: String.Encoding.utf8)
            analyseFile(UnsafeMutablePointer<Int8>(mutating: name!));
        }
//       listdir("/var/mobile/Containers/Data/Application",0);
//       listdir("/var/containers/Bundle/Application",0);
//       listdir("/usr/lib",0);
//       listdir("/Applications",0);
        Jailstatfs();

        let text="SomeText"
        let status=FileManager.default.createFile(atPath: "/var/mobile/Containers/Data/Application/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/var/mobile/Containers/Data/Application/test.txt :")
        if(status)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
//            NSLog("\nalso delete this file and check for other paths too\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status1=FileManager.default.createFile(atPath: "/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/test.txt :")
        if(status1)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status2=FileManager.default.createFile(atPath: "/Applications/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/Applications/test.txt :")
        if(status2)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status3=FileManager.default.createFile(atPath: "/private/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/private/test.txt :")
        if(status3)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status4=FileManager.default.createFile(atPath: "/private/var/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/private/var/test.txt :")
        if(status4)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status5=FileManager.default.createFile(atPath: "/private/var/root/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/private/var/root/test.txt :")
        if(status5)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status6=FileManager.default.createFile(atPath: "/private/var/mobile/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/private/var/mobile/test.txt :")
        if(status6)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }
        
        let status7=FileManager.default.createFile(atPath: "/Developer/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/Developer/test.txt :")
        if(status7)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status8=FileManager.default.createFile(atPath: "/Library/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/Library/test.txt :")
        if(status8)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }
        
        let status9=FileManager.default.createFile(atPath: "/System/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/System/test.txt :")
        if(status9)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status10=FileManager.default.createFile(atPath: "/bin/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/bin/test.txt :")
        if(status10)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status11=FileManager.default.createFile(atPath: "/cores/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/cores/test.txt :")
        if(status11)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status12=FileManager.default.createFile(atPath: "/dev/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/dev/test.txt :")
        if(status12)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status13=FileManager.default.createFile(atPath: "/sbin/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/sbin/test.txt :")
        if(status13)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }
        
        let status14=FileManager.default.createFile(atPath: "/tmp/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/tmp/test.txt :")
        if(status14)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status15=FileManager.default.createFile(atPath: "/usr/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/usr/test.txt :")
        if(status15)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }
       
        let status16=FileManager.default.createFile(atPath: "/var/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/var/test.txt :")
        if(status16)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status17=FileManager.default.createFile(atPath: "/var/containers/Bundle/Application/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/var/containers/Bundle/Application/test.txt :")
        if(status17)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status18=FileManager.default.createFile(atPath: "/var/mobile/Containers/Bundle/Application/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/var/mobile/Containers/Bundle/Application/test.txt :")
        if(status18)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status19=FileManager.default.createFile(atPath: "/private/var/keybags/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/private/var/keybags/test.txt :")
        if(status19)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status20=FileManager.default.createFile(atPath: "/Library/Keychains/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/Library/Keychains/test.txt :")
        if(status20)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status21=FileManager.default.createFile(atPath: "/private/var/Keychains/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/private/var/Keychains/test.txt :")
        if(status21)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status22=FileManager.default.createFile(atPath: "/Library/Ringtones/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/Library/Ringtones/test.txt :")
        if(status22)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status23=FileManager.default.createFile(atPath: "/Library/Wallpaper/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/Library/Wallpaper/test.txt :")
        if(status23)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status24=FileManager.default.createFile(atPath: "/usr/libexec/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/usr/libexec/test.txt :")
        if(status24)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status25=FileManager.default.createFile(atPath: "/usr/share/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/usr/share/test.txt :")
        if(status25)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status26=FileManager.default.createFile(atPath: "/private/var/mobile/Library/Caches/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/private/var/mobile/Library/Caches/test.txt :")
        if(status26)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status27=FileManager.default.createFile(atPath: "/private/var/mobile/Library/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/private/var/mobile/Library/test.txt :")
        if(status27)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status28=FileManager.default.createFile(atPath: "/private/var/tmp/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/private/var/tmp/test.txt :")
        if(status28)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status29=FileManager.default.createFile(atPath: "/private/var/mobile/Containers/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/private/var/mobile/Containers/test.txt :")
        if(status29)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }

        let status30=FileManager.default.createFile(atPath: "/private/var/mobile/Downloads/test.txt", contents: (text as NSString).data(using: String.Encoding.utf8.rawValue), attributes: nil)
        NSLog("\n\n/private/var/mobile/Downloads/test.txt :")
        if(status30)
        {
            NSLog("\nFile written outside sandbox: Jailbroken\n")
            
        }
        else
        {
            NSLog("\nFile can't be written outside sandbox: Non-Jailbroken\n")
        }
        
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}
