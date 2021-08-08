#include <iostream>
#include<string>
#include<unistd.h>


using namespace std;

bool startWg()
{
    system("sudo -S 1 -S  systemctl start wg-quick@wg0");
    return true;
}

bool stopWg()
{
    system("sudo -S  systemctl stop wg-quick@wg0");
    return true;
}

bool statusWg()
{
    system("sudo -S  systemctl status wg-quick@wg0");
    sleep(5);
    system("xdotool key ctrl+c");
    return true;
}
bool restartWg()
{
    system("sudo -S  systemctl restart wg-quick@wg0");
    return true;
}

void configWg()
{
    cout<<">> Config Menu <<!\n";
    cout<<"1. AutoGen Config File\n2. Status Delay Time\n3. Internal IP\n4. Wireguard Mode (Client/Server)";
    int input;
    cin>>input;
    switch(input)
    {
        case 0: return;
        break;
        case 1: echo " [Interface]\n
                     "Address = 192.168.1.1/32\n"
                     "#SaveConfig = true\n"
                     "PostUp = iptables -A FORWARD -i %i -j ACCEPT; iptables -t nat -A POSTROUTING -o eno1 -j MASQUERADE; iptables -A FORWARD -o %i -j ACCEPT\n"
                     "PostDown = iptables -D FORWARD -i %i -j ACCEPT; iptables -t nat -D POSTROUTING -o eno1 -j MASQUERADE; iptables -D FORWARD -o %i -j ACCEPT\n"
                     "ListenPort = 51820\n"
                     "PrivateKey = QEfbBuBad5pgNgwEoBFg7aW5NjWxKzHVFT+DyAwRjnQ=\n"
                     "\n"
                     "[Peer]\n"
                     "PublicKey = PMBzWKkQckqSex1TObsOXZ4CGy9VX7op+iP7N+j3tBw=\n"
                     "AllowedIPs = 192.168.1.2/32\n"
                     "\n"
                     "[Peer]\n"
                     "PublicKey = pOuyY0P19ZgeL3eGZ1wzF8oiFu5e2BK0n/jnUsV0knM=\n"
                     "AllowedIPs = 192.168.1.3/32\n"
                     "\n"
                     "[Peer]\n"
                     "PublicKey = AtNkSW7EbDjxxqnbHr/yhD/5ebZTPFHqpPsrXCz/RUQ=\n"
                     "AllowedIPs = 192.168.1.4/32" >
    }


}

void menu()
{
    bool exit = false;
    while(!exit)
    {
    cout<<"Welcome to EasyWG!\n";
    cout<<"1. Start\n2. Stop\n3. Status\n4. Restart\n5. Config\n6. Quit\n>> ";
    int input;


        cin>>input;
        switch(input)
        {
            case 1: startWg();
            break;
            case 2: stopWg();
            break;
            case 3: statusWg();
            break;
            case 4: restartWg();
            break;
            case 5: startWg();
            break;
            case 6: exit = true;
            break;
        }
    }

}

void firstRun()
{
    cout<<"Welcome to EasyWg, please choose your distribution:";
    cout<<"1. Ubuntu\n2. Debian\n3. Fedora\n4. Mageia\n5.Arch\n6. OpenSUSE\n7. Slackware\n8. Alpine\n9. Gentoo\n10. Exherbo\n11. Oracle Linux 8\n12. Red Hat Linux 8\n13. CentOS\n14. FreeBSD\n>> ";
    int input;
    cin>>input;
    switch(input)
    {
        case 1:system("sudo -S  apt install wireguard");
            break;
            case 2:system("sudo -S  apt install wireguard");
            break;
            case 3:system("sudo -S  dnf install wireguard-tools");
            break;
            case 4:system("sudo -S  urpmi wireguard-tools");
            break;
            case 5:system("sudo -S  pacman -S wireguard-tools");
            break;
            case 6:system("sudo -S  zypper install wireguard-tools");
            break;
            case 7:system("for i in wireguard-linux-compat wireguard-tools; do wget https://slackbuilds.org/slackbuilds/14.2/network/$i.tar.gz && tar -xzf $i.tar.gz && cd $i && OUTPUT=$(pwd) ./$i.SlackBuild && sudo -S  upgradepkg --install-new ./$i*.tgz && cd ..; done");
            break;
            case 8:system("apk add -U wireguard-tools");
            break;
            case 9:system("emerge wireguard-tools");
            break;
            case 10:system("cave resolve -x wireguard");
            break;
            case 11:system("# dnf install oraclelinux-developer-release-el8\n"
                           "# dnf config-manager --disable ol8_developer\n"
                           "# dnf config-manager --enable ol8_developer_UEKR6\n"
                           "# dnf config-manager --save --setopt=ol8_developer_UEKR6.includepkgs='wireguard-tools*'\n"
                           "# dnf install wireguard-tools");
            break;
            case 12:system("$ sudo -S  yum install https://dl.fedoraproject.org/pub/epel/epel-release-latest-8.noarch.rpm https://www.elrepo.org/elrepo-release-8.el8.elrepo.noarch.rpm\n"
                           "$ sudo -S  yum install kmod-wireguard wireguard-tools");
            break;
            case 13:system("$ sudo -S  yum install yum-utils epel-release\n"
                           "$ sudo -S  yum-config-manager --setopt=centosplus.includepkgs=\"kernel-plus, kernel-plus-*\" --setopt=centosplus.enabled=1 --save\n"
                           "$ sudo -S  sed -e 's/^DEFAULTKERNEL=kernel-core$/DEFAULTKERNEL=kernel-plus-core/' -i /etc/sysconfig/kernel\n"
                           "$ sudo -S  yum install kernel-plus wireguard-tools\n"
                           "$ sudo -S  reboot");
            break;
            case 14:system("pkg install wireguard");
            break;
        default: cout<<"Invalid!";
    }

}





int main() {
    bool firstRun = false;
    menu();
    return 0;
}
