# [SendBird](https://sendbird.com) - Messaging and Chat API for Mobile Apps and Websites
[SendBird](https://sendbird.com) provides the chat API and SDK for your app enabling real-time communication among your users.

[![Platform](https://img.shields.io/badge/Platform-iOS-orange.svg)](https://cocoapods.org/pods/SendBirdSDK)
[![Languages](https://img.shields.io/badge/Language-Objective--C%20%7C%20Swift-orange.svg)](https://github.com/sendbird/sendbird-ios-framework)
[![CocoaPods](https://img.shields.io/badge/CocoaPods-compatible-green.svg)](https://cocoapods.org/pods/SendBirdSDK)
[![Carthage compatible](https://img.shields.io/badge/Carthage-compatible-4BC51D.svg?style=flat)](https://github.com/Carthage/Carthage)
[![Commercial License](https://img.shields.io/badge/License-Commercial-brightgreen.svg)](https://github.com/sendbird/sendbird-ios-framework/blob/master/LICENSE.md)

## Documentation
https://docs.sendbird.com/

## Install SendBird Framework from CocoaPods

Add below into your Podfile on Xcode.

```
platform :ios, '8.0'
use_frameworks!

target YOUR_PROJECT_TARGET do
  pod 'SendBirdSDK'
end
```

Install SendBird Framework through CocoaPods.

```
pod install
```

Now you can see installed SendBird framework by inspecting YOUR_PROJECT.xcworkspace.

## Install SendBird Framework from Carthage

1. Add `github "sendbird/sendbird-ios-framework"` to your `Cartfile`.
2. Run `carthage update`.
3. Go to your Xcode project's "General" settings. Open `<YOUR_XCODE_PROJECT_DIRECTORY>/Carthage/Build/iOS` in Finder and drag `SendBirdSDK.framework` to the "Embedded Binaries" section in Xcode. Make sure `Copy items if needed` is selected and click `Finish`.

## [SyncManager](https://github.com/sendbird/sendbird-syncmanager-ios)
[SyncManager SDK](https://github.com/sendbird/sendbird-syncmanager-ios) is a support add-on for [SendBird SDK](https://github.com/sendbird/sendbird-ios-framework). Major benefits of [SyncManager](https://github.com/sendbird/sendbird-syncmanager-ios) are,  
  
 * Local cache integrated: store channel/message data in local storage for fast view loading.  
 * Event-driven data handling: subscribe channel/message event like `insert`, `update`, `remove` at a single spot in order to apply data event to view.  
  
Check out [iOS Sample with SyncManager](https://github.com/sendbird/SendBird-iOS/tree/master/syncmanager) which is same as [iOS Sample](https://github.com/sendbird/SendBird-iOS) with [SyncManager](https://github.com/sendbird/sendbird-syncmanager-ios) integrated.    
For more information about [SyncManager](https://github.com/sendbird/sendbird-syncmanager-ios) integrated, please refer to [SyncManager README](https://github.com/sendbird/sendbird-syncmanager-ios/blob/master/README.md). 
