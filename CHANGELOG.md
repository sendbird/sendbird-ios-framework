# Change Log

### v2.0.22(Mar 6, 2016)
* Bitcode enabled

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
