# Change Log

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
