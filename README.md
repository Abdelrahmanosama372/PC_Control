# PC_Control

PC_Control is a project aimed at controlling your PC remotely using your smartphone. It involves setting up a server on your PC written in C++, where you can connect via your phone to send and execute scripts. The supported script types include JavaScript (js), Python (py), Bash (bash), and Shell (sh) scripts. After executing the script, the server returns the status to the user indicating whether the script was executed successfully or not.

## Features

- Remote control of your PC using a smartphone.
- Supports execution of JavaScript, Python, Bash, and Shell scripts.
- Provides status feedback after script execution.
- Scripts must be located in a folder named `.scripts` in the user's home directory.
- the port used by the server is `8070`

## Installation

1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/Abdelrahmanosama372/PC_Control.git
    ```

2. Navigate to the project directory:

    ```bash
    cd PC_Control
    ```

3. Create and navigate to the build directory:

    ```bash
    mkdir build
    cd build
    ```

4. Generate the build files using CMake:

    ```bash
    cmake ..
    ```

5. Build the server:

    ```bash
    make
    ```

## Usage

1. Start the server:

    ```bash
    ./PC_control
    ```

2. Connect to the server using a TCP client.

3. Select the script you want to execute and send it to the server.

4. The server will execute the script and return the status of the execution to the client.

## Smartphone Client App

You can use the TCP/UDP Server & Client app available on Google Play Store to connect to the server from your smartphone:
[Download TCP/UDP Server & Client App](https://play.google.com/store/apps/details?id=tcpudpserverclient.steffenrvs.tcpudpserverclient&hl=en&gl=US)


## Contributing

Contributions are welcome! If you have any ideas for improvement or bug fixes, feel free to open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

---