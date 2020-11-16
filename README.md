# [Sendbird](https://sendbird.com) Chat SDK for iOS (Objective-C)

[![Platform](https://img.shields.io/badge/Platform-iOS-orange.svg)](https://cocoapods.org/pods/SendBirdSDK)
[![Languages](https://img.shields.io/badge/Language-Objective--C%20%7C%20Swift-orange.svg)](https://github.com/sendbird/sendbird-ios-framework)
[![CocoaPods](https://img.shields.io/badge/CocoaPods-compatible-green.svg)](https://cocoapods.org/pods/SendBirdSDK)
[![Carthage compatible](https://img.shields.io/badge/Carthage-compatible-4BC51D.svg?style=flat)](https://github.com/Carthage/Carthage)
[![Commercial License](https://img.shields.io/badge/License-Commercial-brightgreen.svg)](https://github.com/sendbird/sendbird-ios-framework/blob/master/LICENSE.md)

## Introduction

### What it is

Through Chat SDK for iOS, you can efficiently integrate real-time chat into your client app. On the client-side implementation, you can initialize, configure and build the chat with minimal effort. On the server-side, Sendbird ensures reliable infra-management services for your chat within the app. This **read.me** provides the Chat SDK’s structure, supplementary features, and the installation steps. 

### How it works

It is simple to implement chat in your client app with the Chat SDK: a user logs in, sees a list of channels, selects or creates an [open channel](https://sendbird.com/docs/chat/v3/ios/guides/open-channel) or a [group channel](https://sendbird.com/docs/chat/v3/ios/guides/group-channel), and, through the use of the [channel event delegates](https://sendbird.com/docs/chat/v3/ios/guides/event-delegate), sends messages to the channel, while also receiving them from other users within the channel. 

### More about Sendbird Chat SDK for iOS

Find out more about Sendbird Chat for iOS on [Chat SDK for iOS doc](https://sendbird.com/docs/chat/v3/ios/getting-started/about-chat-sdk). 

<br />

## Before getting started

This section shows you the prerequisites you need for testing Sendbird Calls for iOS sample app.

### Requirements

The minimum requirements for Chat SDK for iOS sample are:

- Mac OS with developer mode enabled
- Xcode
- At least one physical iOS device running iOS 9.0 and later
- Swift 4.0 and later

### Add-ons for Sendbird Chat SDK 

Try building your Sendbird application with these two add-ons.  

- [Sendbird UIKit for iOS](https://github.com/sendbird/UIKit-iOS-Swift): a development kit with an user interface that enables an easy and fast integration of standard chat features into new or existing client apps.

- [Sendbird SyncManager for iOS](https://github.com/sendbird/SyncManager-iOS-Swift): a Chat SDK add-on that optimizes the user caching experience by interlinking the synchronization of the local data storage with the chat data in Sendbird server through an event-driven structure. 

<br />

## Getting started

### Try the sample app

The fastest way to test Chat SDK is to build your chat app on top of our sample app. To create a project for the sample app, download the app from our GitHub repository.


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
