# [Sendbird](https://sendbird.com) Chat SDK for iOS (Objective-C)

[![Platform](https://img.shields.io/badge/Platform-iOS-orange.svg)](https://cocoapods.org/pods/SendBirdSDK)
[![Languages](https://img.shields.io/badge/Language-Objective--C%20%7C%20Swift-orange.svg)](https://github.com/sendbird/sendbird-ios-framework)
[![CocoaPods](https://img.shields.io/badge/CocoaPods-compatible-green.svg)](https://cocoapods.org/pods/SendBirdSDK)
[![Carthage compatible](https://img.shields.io/badge/Carthage-compatible-4BC51D.svg?style=flat)](https://github.com/Carthage/Carthage)
[![Commercial License](https://img.shields.io/badge/License-Commercial-brightgreen.svg)](https://github.com/sendbird/sendbird-ios-framework/blob/master/LICENSE.md)

## Table of contents

  1. [Introduction](#introduction)
  1. [Before getting started](#before-getting-started)
  1. [Getting started](#getting-started)
  1. [Sending your first message](#sending-your-first-message)
  1. [Notice](#notice)

<br />

## Introduction

Through Chat SDK for iOS, you can efficiently integrate real-time chat into your client app. On the client-side implementation, you can initialize, configure and build the chat with minimal effort. On the server-side, Sendbird ensures reliable infra-management services for your chat within the app. This **read.me** provides the Chat SDK’s structure, supplementary features, and the installation steps. 

### How it works

It is simple to implement chat in your client app with the Chat SDK: a user logs in, sees a list of channels, selects or creates an [open channel](https://sendbird.com/docs/chat/v3/ios/guides/open-channel) or a [group channel](https://sendbird.com/docs/chat/v3/ios/guides/group-channel), and, through the use of the [channel event delegates](https://sendbird.com/docs/chat/v3/ios/guides/event-delegate), sends messages to the channel, while also receiving them from other users within the channel. 

### More about Sendbird Chat SDK for iOS

Find out more about Sendbird Chat for iOS on [Chat SDK for iOS doc](https://sendbird.com/docs/chat/v3/ios/getting-started/about-chat-sdk). If you have any comments or questions regarding bugs and feature requests, visit [Sendbird community](https://community.sendbird.com). 

<br />

## Before getting started

This section shows you the prerequisites you need to check for using Sendbird Chat SDK for iOS. 

### Requirements

The minimum requirements for Chat SDK for iOS are:

- Mac OS with developer mode enabled
- Xcode
- At least one physical iOS device running iOS 9.0 and later
- Swift 4.0 and later

### Add-ons for Sendbird Chat SDK 

Try building your Sendbird application with these two add-ons:

- [Sendbird UIKit for iOS](https://github.com/sendbird/UIKit-iOS-Swift): a development kit with an user interface that enables an easy and fast integration of standard chat features into new or existing client apps.

- [Sendbird SyncManager for iOS](https://github.com/sendbird/SyncManager-iOS-Swift): a Chat SDK add-on that optimizes the user caching experience by interlinking the synchronization of the local data storage with the chat data in Sendbird server through an event-driven structure. 

<br />

## Getting started

This section gives you information you need to get started with Sendbird Chat SDK for iOS. Follow the simple steps below to build the Chat SDK into your client app.

### Try the sample app

The fastest way to test Chat SDK is to build your chat app on top of our sample app. To create a project for the sample app, download the app from our GitHub repository. The link is down below. 

- https://github.com/sendbird/Sendbird-iOS

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
platform :ios, '9.0'
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

```objectivec
#import <SendBirdSDK/SendBirdSDK.h>
```

The [Interacting with Objective-C APIs in Swift](https://developer.apple.com/documentation/swift/imported_c_and_objective-c_apis) helps you with understanding how to use the Chat SDK in Swift syntax.

<br />

## Sending your first message

Follow the step-by-step instructions below to authenticate and send your first message.

### Authentication

In order to use the features of the Chat SDK for iOS written in `Objective-C`, you should initiate the `SBDMain` instance through user authentication with Sendbird server. This instance communicates and interacts with the server based on an authenticated user account, and then the user’s client app can use the Chat SDK's features. 

Here are the steps to sending your first message using Chat SDK:

### Step 1: Initialize the Chat SDK

Initializing the Chat SDK allows the Chat SDK to respond to the connection and state changes in your client app. Pass the `APP_ID` of your Sendbird application as an argument to a parameter in the `initWithApplicationId:`. The `initWithApplicationId:` creates a `SBDMain` instance, thus should be called a single time across your client app. It is recommended that the code for initialization be implemented in the user login view. The Chat SDK should be initialized in the `application:didFinishLaunchingWithOptions:` method of the `AppDelegate` instance. 

```objectivec
[SBDMain initWithApplicationId:APP_ID];
```

### Step 2: Connect to Sendbird server

#### A. Using a unique user ID

Connect a user to Sendbird server by using a unique user ID or with a user ID and an access token. To connect to the Sendbird server, a user is required to log in with a unique ID. A new user can authenticate with any untaken user ID, which gets automatically registered to the Sendbird system. An existing ID can log in directly. The ID must be unique within a Sendbird application to be distinguished from others, such as a hashed email address or phone number in your service.

```objectivec
[SBDMain connectWithUserId:USER_ID completionHandler:^(SBDUser * _Nullable user, SBDError * _Nullable error) {
    if (error != nil) { // Error.
        return;
    }
}];
```

#### B. Using a unique user ID and an access token

By using Chat Platform API, you can [create a user](https://sendbird.com/docs/chat/v3/platform-api/guides/user#2-create-a-user) and issue a unique access token to each user, or [issue an access token](https://sendbird.com/docs/chat/v3/platform-api/guides/user#2-update-a-user) for an existing user. Once an access token is issued, a user is required to provide the access token to log in to the Sendbird application.

1. Using the [Chat Platform API](https://sendbird.com/docs/chat/v3/platform-api/guides/user#2-create-a-user), create a Sendbird user account with the information submitted when a user signs up or signs in to your service.
2. Save the user ID along with the issued access token to your securely managed persistent storage. 
3. When a user attempts to log in to the application, load the user ID and access token from the storage, and then pass them to `connectWithUserId:accessToken:completionHandler:` method.
4. Periodically replacing the user's access token is recommended for account security.

```objectivec
[SBDMain connectWithUserId:USER_ID accessToken:ACCESS_TOKEN completionHandler:^(SBDUser * _Nullable user, SBDError * _Nullable error) {
    if (error != nil) { // Error.
        return;
    }
}];
```

#### - Tips for secure user login

To manage who can access your Sendbird application, go to **Settings** > **Application** > **Security** > **Access token permission** setting on your dashboard. You can change settings to prevent users without an access token from logging in to your application or restrict their access to read and write messages.
For security reasons, you can also use a session token when a user logs in to Sendbird server instead of an access token. Go to the [Access token vs. Session token](https://sendbird.com/docs/chat/v3/platform-api/guides/user#2-create-a-user-3-access-token-vs-session-token) section from the Chat Platform API guide to learn more.

### Step 3: Create a new open channel

Create an [open channel](https://sendbird.com/docs/chat/v3/ios/guides/open-channel#2-create-a-channel). Once created, all users in your Sendbird application can easily participate in the channel.

```objectivec
[SBDOpenChannel createChannelWithCompletionHandler:^(SBDOpenChannel * _Nullable openChannel, SBDError * _Nullable error) {
    if (error != nil) { // Error.
        return;
    }
}];
```

You can also create a [group channel](https://sendbird.com/docs/chat/v3/ios/guides/group-channel#2-create-a-channel) by [inviting users as new members](https://sendbird.com/docs/chat/v3/ios/guides/group-channel#2-invite-users-as-members) to the channel.

> Note: The majority of the methods used in the following steps are all asynchronous except initWithApplicationId:. This means with asynchronous methods, your client app must receive success callbacks from Sendbird server through completion handlers  before moving on to the next step.  

### Step 4: Enter the channel

Enter the channel to send and receive messages.

```objectivec
[SBDOpenChannel getChannelWithUrl:CHANNEL_URL completionHandler:^(SBDOpenChannel * _Nullable openChannel, SBDError * _Nullable error) {
    if (error != nil) { // Error.
        return;
    }
    
    [openChannel enterChannelWithCompletionHandler:^(SBDError * _Nullable error) {
        if (error != nil) { // Error.
            return;
        }
    }];
}];
```

### Step 5: Send a message to the channel 

Finally, send a message to the channel. There are three types of [messages](https://sendbird.com/docs/chat/v3/platform-api/guides/messages#-3-resource-representation): a user message in a plain text, a file message in a binary file, such as an image or PDF, and an admin message in a plain text sent through the [dashboard](https://dashboard.sendbird.com/auth/signin) or [Chat Platform API](https://sendbird.com/docs/chat/v3/platform-api/guides/messages#2-send-a-message).

```objectivec
[openChannel sendUserMessage:MESSAGE data:DATA customType:CUSTOM_TYPE completionHandler:^(SBDUserMessage * _Nullable userMessage, SBDError * _Nullable error) {
    if (error != nil) { // Error. 
        return;
    }
}];
```
## Notice

### v.3.1.0 Release (Local Caching)

Local caching has been introduced to the Chat SDK in this v3.1.0 release. The newly embedded local caching functionalities can be enabled through a parameter `useCaching` in the `SBDMain.initWithApplicationId()`. When local caching is turned off, the SDK is backward compatible with v3.0. This means it will work exactly the same as v3.0 and therefore is compatible with SyncManager. However, we strongly recommend you to use the Chat SDK with local caching instead of SyncManager for the following reasons:
Sendbird Chat SDK with local caching supports new functionalities such as group channel collection, message collection, and message auto-resend.
SyncManager will be deprecated eventually as the embedded local caching serves as the new and better version of it.

For further information, please see our [Docs](https://sendbird.com/docs/chat/v3/ios/guides/local-caching).
Additionally, migration guide for clients currently using SyncManager will be available soon.