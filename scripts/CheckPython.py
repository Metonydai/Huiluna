import subprocess
import importlib.util

def install(package):
    print(f"Installing {package} module...")
    subprocess.check_call(['python', '-m', 'pip', 'install', package])

def ValidatePackage(package):
    if importlib.util.find_spec(package) is None:
            install(package)

def ValidatePackages():
    ValidatePackage('requests')
    ValidatePackage('fake-useragent')
