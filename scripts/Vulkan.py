import os
import subprocess
import sys
from pathlib import Path

import Utils

from io import BytesIO
from urllib.request import urlopen
from zipfile import ZipFile

VULKAN_SDK = os.environ.get('VULKAN_SDK')
VULKAN_SDK_INSTALLER_URL = 'https://sdk.lunarg.com/sdk/download/1.3.296.0/windows/VulkanSDK-1.3.296.0-Installer.exe'
HUILUNA_VULKAN_VERSION = '1.3.296.0'
VULKAN_SDK_EXE_PATH = 'Huiluna/vendor/VulkanSDK/VulkanSDK.exe'

def InstallVulkanSDK():
    print('Downloading {} to {}'.format(VULKAN_SDK_INSTALLER_URL, VULKAN_SDK_EXE_PATH))
    Utils.DownloadFile(VULKAN_SDK_INSTALLER_URL, VULKAN_SDK_EXE_PATH)
    print("Done!")
    print("Running Vulkan SDK installer...")
    os.startfile(os.path.abspath(VULKAN_SDK_EXE_PATH))
    print("Re-run this script after installation")

def InstallVulkanPrompt():
    print("Would you like to install the Vulkan SDK?")
    install = Utils.YesOrNo()
    if (install):
        InstallVulkanSDK()
        quit()

def CheckVulkanSDK():
    if (VULKAN_SDK is None):
        print("You don't have the Vulkan SDK installed!")
        InstallVulkanPrompt()
        return False
    elif (HUILUNA_VULKAN_VERSION not in VULKAN_SDK):
        print(f"Located Vulkan SDK at {VULKAN_SDK}")
        print(f"You don't have the correct Vulkan SDK version! (Huiluna requires {HUILUNA_VULKAN_VERSION})")
        InstallVulkanPrompt()
        return False
    
    print(f"Correct Vulkan SDK located at {VULKAN_SDK}")
    return True

def CheckVulkanSDKDebugLibs():
    shadercdLib = Path(f"{VULKAN_SDK}/Lib/shaderc_sharedd.lib")
    if (not shadercdLib.exists()):
        print(f"No Vulkan SDK debug libs found. (Checked {shadercdLib})")
        return False
    
    print(f"Vulkan SDK debug libs found. (Checked {shadercdLib})")

    return True
