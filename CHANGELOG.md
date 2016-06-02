# Change Log

### v2.2.9(Jun 2, 2016)
* Fixed crash bug

### v2.2.8(Jun 1, 2016)
* Fixed connection bug without channel url

### v2.2.7(May 27, 2016)
* Fixed login bug

### v2.2.5(May 24, 2016)
* Improved performance of logging in

### v2.2.4(May 17, 2016)
* Added methods for push registration and unregistration
* Added method for creating group messaging channel

### v2.2.3(May 13, 2016)
* Fixed memory leak

### v2.2.2(May 13, 2016)
* Fixed message parsing bug
* Changed the way to try to reconnect

### v2.2.1(May 8, 2016)
* Fixed ARC bug

### v2.2.0(May 4, 2016)
* **DO NOT USE THIS VERSION**

### v2.1.1(Apr 21, 2016)
* Fixed bug of uploading video file.
* Deprecated `[SendBird uploadFile:type:hasSizeOfFile:withCustomField:uploadBlock:]` method
* Added `[SendBird uploadFile:filename:type:hasSizeOfFile:withCustomField:uploadBlock:]` method

### v2.1.0(Apr 19, 2016)
* Added routing for getting server address
* Fixed malformed command

### v2.0.28(Mar 28, 2016)
* Changed parameter name of a block

### v2.0.27(Mar 27, 2016)
* Fixed bug of session control in background

### v2.0.26(Mar 17, 2016)
* Added received events for muted message and file to `setEventHandler`

### v2.0.25(Mar 16, 2016)
* Added system event for mute

### v2.0.24(Mar 16, 2016)
* Added meta data and meta counter for channel
* Added muted property to user and message
* Added message query method by timestamp
* Added new system event

### v2.0.23(Mar 6, 2016)
* Bitcode enabled

### v2.0.22(Mar 6, 2016)
* **DO NOT USE THIS VERSION**

### v2.0.21(Mar 3, 2016)
* Added delete message method
* Added the property for user online/offline

### v2.0.20(Feb 18, 2016)
* Fixed crash bug when switching between foreground and background

### v2.0.16(Feb 15, 2016)
* Replaced NSURLConnection with NSURLSession

### v2.0.15(Feb 9, 2016)
* Added api for counting online member

### v2.0.13(Jan 28, 2016)
* Fixed WebSocket bug.

### v2.0.11(Jan 20, 2016)
* Support Swift.

### v2.0.5(Jan 13, 2016)
* Added new feature to get user list in app.

### v2.0.0(Jan 4, 2016)
* Changed the framework and classess name to SendBird.

### v1.1.43
* Improved performance of user block.

### v1.1.42
* Fixed bug of user block.

### v1.1.41

* Deprecated ```[Jiver initAppId:selectDeviceId:]``` method.
* Deprecated ```[Jiver igawInitAppId:selectDeviceId:]``` method.
* Added ```[Jiver initAppId:withDeviceId:]``` method. This method replaced ```[Jiver initAppId:selectDeviceId:]```.
* Added ```[Jiver igawInitAppId:withDeviceId:]``` method. This method replaced ```[Jiver igawInitAppId:selectDeviceId:]```.
* Removed all codes which refer to IDFA.

### v1.1.40

* Removed ```JiverMessagingChannelListQuery executeWithResultBlock:endBlock:]```.
* Added new methods to ```JiverMessagingChannelListQuery```

```
- setLimit:
- hasNext
- nextWithResultBlock:endBlock:
```
