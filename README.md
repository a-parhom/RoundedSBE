## This repository is archived now. Please, use [LightlyShaders](https://github.com/a-parhom/LightlyShaders) effect, which works with any window decorations.

# RoundedSBE

This is a fork of **SierraBreezeEnhanced** with integrated corner rounding effect **CornersShader** (reworked version of **LightlyShaders**). The main purpose of this fork is the shared configuration for both window decoration and corner rounding effect, as well as opportunity to use window rules, that were implemented in SBE, together with CornersShader effect.

## Overview

RoundedSBE has the following main features:

 * Button style options: Plasma / Gnome / macOS Sierra / macOS Dark Aurorae / SBE Sierra themes / SBE Dark Aurorae themes / Color Symbols themes / Monochrome Symbols themes (Note: the application menu button is considered special and does not change).
 * Button spacing and padding Options.
 * Button hovering animation.
 * Option to make all button symbols to appear at unison on hovering (Note: it does not apply to symbol themes).
 * Titlebar style options: SBE own style of Line Separation between Titlebar and Window / Match Titlebar color to Window color / Hide Titlebar under certain circumstances (Never/Maximization/Any Maximization (including H/V)/Always) / Gradient Adjustments / Opacity Adjustments.
 * Specific Shadow settings for inactive windows.
 * Option to force rounded corners (top and bottom) for all windows, including CSD.
 * Settings for window corners shape: rounded or squircled.
 
 
### Screenshot of RoundedSBE


![Active Buttons](screenshots/ActiveButtons.gif?raw=true "Active Buttons")
![Inactive Buttons](screenshots/InactiveButtons.gif?raw=true "Inactive Buttons")


### Screenshot of Settings


![SBE Settings](screenshots/SBE_settings.png?raw=true "SBE Settings")


## Installation

Please note that after installing, you need to restart KWin by executing either `kwin_x11 --replace` or `kwin_wayland --replace` in krunner (depending on whether your session runs upon X11 or Wayland). Alternatively, restarting the KDE session is obviously also an option. Then, RoundedSBE will appear in *System Settings &rarr; Appearance &rarr; Window Decorations* and CornersShader will appear in *System Settings &rarr; Workspace Behavior &rarr; Desktop Effects*.

In order for the rounded corners to be displayed correctly, you need to set the *`Window border size`* (*System Settings &rarr; Appearance &rarr; Window Decorations*) to *`No Borders`*.

### Compile from source code
*Compilation should not be done against versions of KWin < 5.27.*

#### Step 1: Build dependencies
- Ubuntu
``` shell
sudo apt install build-essential libkf5config-dev libkdecorations2-dev libqt5x11extras5-dev qtdeclarative5-dev extra-cmake-modules libkf5guiaddons-dev libkf5configwidgets-dev libkf5windowsystem-dev libkf5coreaddons-dev libkf5iconthemes-dev gettext git cmake g++ qttools5-dev libkf5crash-dev libkf5globalaccel-dev libkf5kio-dev libkf5notifications-dev kinit-dev kwin-dev 
```
- Arch Linux
``` shell
sudo pacman -S git make cmake gcc gettext extra-cmake-modules qt5-tools kcrash kglobalaccel kde-dev-utils kio knotifications kinit kwin kdecoration qt5-declarative qt5-x11extras
```
- Fedora
``` shell
sudo dnf install git cmake gcc-c++ extra-cmake-modules
sudo dnf install "cmake(Qt5Core)" "cmake(Qt5Gui)" "cmake(Qt5DBus)" "cmake(Qt5X11Extras)" "cmake(KF5GuiAddons)" "cmake(KF5WindowSystem)" "cmake(KF5I18n)" "cmake(KDecoration2)" "cmake(KF5CoreAddons)" "cmake(KF5ConfigWidgets)"
sudo dnf install qt5-qttools-devel qt5-qttools-static qt5-qtx11extras-devel kf5-kconfigwidgets-devel kf5-kcrash-devel kf5-kguiaddons-devel kf5-kglobalaccel-devel kf5-kio-devel kf5-ki18n-devel kf5-knotifications-devel kf5-kinit-devel kf5-kiconthemes-devel kwin-devel qt5-qtbase-devel libepoxy-devel
```
- OPenSUSE
``` shell
sudo zypper install git cmake gcc-c++ extra-cmake-modules libqt5-qttools-devel libqt5-qtx11extras-devel kconfigwidgets-devel kcrash-devel kguiaddons-devel kglobalaccel-devel kio-devel ki18n-devel knotifications-devel kinit-devel kwin5-devel libQt5Gui-devel libQt5OpenGL-devel libepoxy-devel
```

#### Step 2: Then compile and install
- Install from script:
```sh
chmod +x install.sh
./install.sh
```
- Or more manually:
Open a terminal inside the source directory and do:
```sh
mkdir build && cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release -DKDE_INSTALL_LIBDIR=lib -DBUILD_TESTING=OFF -DKDE_INSTALL_USE_QT_SYS_PATHS=ON
make
sudo make install
```


## Uninstall

- Method 1: Run the uninstall script
```sh
chmod +x uninstall.sh
./uninstall.sh
```
- Method 2: or manually if previously ran the install script
```sh
cd build
sudo make uninstall
```


## Credits
Breeze, Sierra Breeze, Breeze Enhanced, Sierra Breeze Enhanced, ShapeCorners and LightlyShaders for obvious reasons :)
