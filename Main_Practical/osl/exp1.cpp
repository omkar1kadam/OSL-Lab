#include <iostream>
#include <unistd.h>     // read, write, close
#include <fcntl.h>      // open
#include <cstring>      // strlen

using namespace std;

int main() {
    cout << "🚀 Program started...\n";

    // ================= CREATE / OPEN FILE =================
    cout << "\n[STEP 1] Opening/Creating file using open()\n";

    int fd = open("test.txt", O_CREAT | O_WRONLY, 0644);

    if (fd < 0) {
        cout << "❌ ERROR: Failed to open file!\n";
        return 1;
    }

    cout << "✅ File opened successfully\n";
    cout << "👉 File Descriptor (fd): " << fd << "\n";


    // ================= WRITE TO FILE =================
    cout << "\n[STEP 2] Writing data to file using write()\n";

    const char *msg = "Hello bro, only file system calls here!\n";

    int bytesWritten = write(fd, msg, strlen(msg));

    if (bytesWritten < 0) {
        cout << "❌ ERROR: Write failed!\n";
        close(fd);
        return 1;
    }

    cout << "✅ Write successful\n";
    cout << "👉 Bytes Written: " << bytesWritten << "\n";


    // ================= CLOSE FILE =================
    cout << "\n[STEP 3] Closing file using close()\n";

    close(fd);
    cout << "✅ File closed successfully\n";


    // ================= REOPEN FOR READING =================
    cout << "\n[STEP 4] Re-opening file in read mode\n";

    fd = open("test.txt", O_RDONLY);

    if (fd < 0) {
        cout << "❌ ERROR: Failed to open file for reading!\n";
        return 1;
    }

    cout << "✅ File opened for reading\n";
    cout << "👉 File Descriptor (fd): " << fd << "\n";


    // ================= READ FILE =================
    cout << "\n[STEP 5] Reading file using read()\n";

    char buffer[100];
    int bytesRead = read(fd, buffer, sizeof(buffer));

    if (bytesRead < 0) {
        cout << "❌ ERROR: Read failed!\n";
        close(fd);
        return 1;
    }

    cout << "✅ Read successful\n";
    cout << "👉 Bytes Read: " << bytesRead << "\n";

    cout << "\n📄 File Content:\n";
    write(1, buffer, bytesRead);  // direct output


    // ================= FINAL CLOSE =================
    cout << "\n\n[STEP 6] Closing file after reading\n";

    close(fd);
    cout << "✅ File closed successfully\n";

    cout << "\n🏁 Program finished!\n";

    return 0;
}