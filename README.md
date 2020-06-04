# [Sendbird](https://sendbird.com) - Messaging and Chat API for Mobile Apps and Websites
[Sendbird](https://sendbird.com) provides the chat API and SDK for your app enabling real-time communication among your users.

[![Platform](https://img.shields.io/badge/Platform-iOS-orange.svg)](https://cocoapods.org/pods/SendBirdSDK)
[![Languages](https://img.shields.io/badge/Language-Objective--C%20%7C%20Swift-orange.svg)](https://github.com/sendbird/sendbird-ios-framework)
[![CocoaPods](https://img.shields.io/badge/CocoaPods-compatible-green.svg)](https://cocoapods.org/pods/SendBirdSDK)
[![Carthage compatible](https://img.shields.io/badge/Carthage-compatible-4BC51D.svg?style=flat)](https://github.com/Carthage/Carthage)
[![Commercial License](https://img.shields.io/badge/License-Commercial-brightgreen.svg)](https://github.com/sendbird/sendbird-ios-framework/blob/master/LICENSE.md)

## Documentation
https://docs.sendbird.com/

## Install Sendbird Framework from CocoaPods

Add below into your Podfile on Xcode.

```
platform :ios, '8.0'
use_frameworks!

target YOUR_PROJECT_TARGET do
  pod 'SendBirdSDK'
end
```

Install Sendbird Framework through CocoaPods.

```
pod install
```

Now you can see installed Sendbird framework by inspecting YOUR_PROJECT.xcworkspace.

## Install Sendbird Framework from Carthage

1. Add `github "sendbird/sendbird-ios-framework"` to your `Cartfile`.
2. Run `carthage update`.
3. Go to your Xcode project's "General" settings. Open `<YOUR_XCODE_PROJECT_DIRECTORY>/Carthage/Build/iOS` in Finder and drag `SendBirdSDK.framework` to the "Embedded Binaries" section in Xcode. Make sure `Copy items if needed` is selected and click `Finish`.
4. On your application targets’ `Build Phases` settings tab, click the + icon and choose `New Run Script` Phase. Create a Run Script in which you specify your shell (ex: `/bin/sh`), add the following contents to the script area below the shell:
```
/usr/local/bin/carthage copy-frameworks
```
* Add the paths to the frameworks you want to use under “Input Files". For example:
```
$(SRCROOT)/Carthage/Build/iOS/SendBirdSDK.framework
```
* Add the paths to the copied frameworks to the “Output Files”. For example:
```
$(BUILT_PRODUCTS_DIR)/$(FRAMEWORKS_FOLDER_PATH)/SendBirdSDK.framework
```
For an in depth guide, read on from [Adding frameworks to an application](https://github.com/Carthage/Carthage#quick-start)

## [SyncManager](https://github.com/sendbird/sendbird-syncmanager-ios)
[SyncManager SDK](https://github.com/sendbird/sendbird-syncmanager-ios) is a support add-on for [Sendbird SDK](https://github.com/sendbird/sendbird-ios-framework). Major benefits of [SyncManager](https://github.com/sendbird/sendbird-syncmanager-ios) are,  
  
 * Local cache integrated: store channel/message data in local storage for fast view loading.  
 * Event-driven data handling: subscribe channel/message event like `insert`, `update`, `remove` at a single spot in order to apply data event to view.  
  
Check out [iOS Sample with SyncManager](https://github.com/sendbird/SendBird-iOS/tree/master/syncmanager) which is same as [iOS Sample](https://github.com/sendbird/SendBird-iOS) with [SyncManager](https://github.com/sendbird/sendbird-syncmanager-ios) integrated.    
For more information about [SyncManager](https://github.com/sendbird/sendbird-syncmanager-ios) integrated, please refer to [SyncManager README](https://github.com/sendbird/sendbird-syncmanager-ios/blob/master/README.md). 
