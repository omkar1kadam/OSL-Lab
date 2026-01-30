echo "=============================="
echo "System info: $(uname -a)"
echo "=============================="

echo "Kernal info: $(uname -r)"
echo "=============================="
cat /etc/os-release

echo "=============================="
echo "b) Top 10 Processes (CPU usage)"
echo "=============================="

ps -eo pid,ppid,cmd,%cpu --sort=-%cpu | head -n 11
echo "================================"
echo "c) Processes with Highest Memory"
echo "================================"

ps -eo pid,ppid,cmd,%mem,%cpu --sort=-%mem | head -n 11

echo "================================"
echo "d) Logged-in User & Login Name"
echo "================================"

echo "Current User: $(whoami)"
echo "Login Name  : $(logname)"

"chmod +x assign2.sh"
"./assign2.sh"
