# hello_world.py
import PySimpleGUI as sg
import os
layout = [[sg.Text("Welcome to EasyWG")], [sg.Button("QUIT")],[sg.Button("Start Wg")], [sg.Button("Stop Wg")], [sg.Button("Load Config")]]

window = sg.Window(title="EasyWG",layout=layout)

while True:
    event, values = window.read()
    if event == "QUIT" or event == sg.WIN_CLOSED:
        break

    if event == "Start Wg":
        os.system("pkexec systemctl start wg-quick@wg0")

    if event == "Stop Wg":
        os.system("pkexec systemctl stop wg-quick@wg0")

    if event == "Load Config":
        os.system("pkexec cp /home/$USER/config.conf /etc/wireguard/wg0.conf")

window.close()
