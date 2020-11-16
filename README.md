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

The minimum requirements for Chat SDK for iOS are:

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


### Step 1: Create a Sendbird application from your dashboard

A Sendbird application comprises everything required in a chat service including users, message, and channels. To create an application:

1. Go to the [Sendbird Dashboard](https://dashboard.sendbird.com/auth/signup) and enter your email and password, and create a new account. You can also sign up with a Google account.
2. When prompted by the setup wizard, enter your organization information to manage Sendbird applications.
3. Lastly, when your dashboard home appears after completing setup, click **Create +** at the top-right corner.

Only one Sendbird application can be integrated per app for your service regardless of the platform. All users within your Sendbird application can communicate with each other across all platforms. This means that your iOS, Android, and web client app users can all send and receive messages with one another without any further setup.

> Note: All data is limited to the scope of a single application, and users in different Sendbird applications can't chat with each other.

### Step 2: Install SDK via CocoaPods or Carthage

Installing the Chat SDK is a simple process if you’re familiar with using external libraries or SDK’s in your projects. You can install the Chat SDK using [`CocoaPods`](https://cocoapods.org/) or [`Carthage`](https://github.com/Carthage/Carthage) like the following.

#### - CocoaPod

Open a terminal window. Navigate to the project directory, and then open the `Podfile` by running the following command:

```bash
$ pod init
```

On `Podfile`, add the following lines: 

```bash
platform :ios, '8.0'
use_frameworks!

target YOUR_PROJECT_TARGET do
  pod 'SendBirdSDK'
end
```

Install the `SendBird` framework through `CocoaPods`.

```bash
$ pod install
```

Now you can run your project with the `SendBird` framework by opening `*YOUR_PROJECT*.xcworkspace`. If you don't want to use `CocoaPods`, check out the [manual installation guide](https://help.sendbird.com/s/article/iOS-How-can-I-install-SendBird-Framework-without-using-CocoaPods).

#### - Carthage

1. Add `github "sendbird/sendbird-ios-framework"` to your `Cartfile`.
2. Run `carthage update`.
3. Go to your Xcode project's General settings tab. Open the `<YOUR_XCODE_PROJECT_DIRECTORY>/Carthage/Build/iOS` in the Finder window and drag `SendBirdSDK.framework` to the Embedded Binaries section in Xcode. Make sure the `Copy items if needed` option is selected and click `Finish`.
4. On your application targets’ Build Phases settings tab, click the **+** icon and choose **New Run Script Phase**. Create a **Run Script** in which you specify your shell (ex: /bin/sh), add the following contents to the script area below the shell: `/usr/local/bin/carthage copy-frameworks`
5. Add the paths to the frameworks you want to use under **Input Files**.  For example: `$(SRCROOT)/Carthage/Build/iOS/SendBirdSDK.framework`
6. Add the paths to the copied frameworks to the **Output Files**. For example: `$(BUILT_PRODUCTS_DIR)/$(FRAMEWORKS_FOLDER_PATH)/SendBirdSDK.framework`

For an in depth guide, read on from [Adding frameworks to an application](https://github.com/Carthage/Carthage#quick-start).

#### Turn on ARC

To use the `SendBird` framework, you should turn on the ARC (Automatic Reference Counting). To do that, go to your project's **Build Settings**, and then set the value of Objective-C Automatic Reference Counting to Yes (in `Swift`, **Yes** by default).
If you don't want to turn on ARC in a project-wide scope, then navigate to the **Build Phases - Compile Sources** and add `-fobjc-arc` to the **Compiler Flags** in the source file that the `SendBird` framework uses. This means that ARC is turned on only that file.

### Step 3: Use the Chat SDK in Objective-C

You can use all classes and methods just with the following one import statement, without a bridging header file, in both `Objective-C` and `Swift`.

```bash
#import <SendBirdSDK/SendBirdSDK.h>
```

The [Interacting with Objective-C APIs in Swift](https://developer.apple.com/documentation/swift/imported_c_and_objective-c_apis) helps you with understanding how to use the Chat SDK in Swift syntax.

<br />

## Send your first message

### Authentication

In order to use the features of the Chat SDK for iOS written in `Objective-C`, you should initiate the `SBDMain` instance through user authentication with Sendbird server. This instance communicates and interacts with the server based on an authenticated user account, and then the user’s client app can use the Chat SDK's features. 

Here are the steps to sending your first message using Chat SDK:
