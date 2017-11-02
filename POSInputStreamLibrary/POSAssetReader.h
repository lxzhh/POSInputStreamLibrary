//
//  POSAssetReader.h
//  POSInputStreamLibrary
//
//  Created by Pavel Osipov on 08.05.15.
//  Copyright (c) 2015 Pavel Osipov. All rights reserved.
//

#import <AssetsLibrary/AssetsLibrary.h>
@class PHAsset;
FOUNDATION_EXTERN NSString * const POSBlobInputStreamAssetDataSourceErrorDomain;

typedef long long POSLength;

@protocol POSAssetReader

/**
 *  iOS8 later only
 *
 */
- (void)openPHAsset:(PHAsset *)asset
         fromOffset:(POSLength)offset
  completionHandler:(void (^)(POSLength assetSize, NSError *error))completionHandler;

- (void)openAsset:(ALAssetRepresentation *)assetRepresentation
       fromOffset:(POSLength)offset
completionHandler:(void (^)(POSLength assetSize, NSError *error))completionHandler;

- (BOOL)hasBytesAvailableFromOffset:(POSLength)offset;

- (BOOL)prepareForNewOffset:(POSLength)offset;

- (NSInteger)read:(uint8_t *)buffer
       fromOffset:(POSLength)offset
        maxLength:(NSUInteger)maxLength
            error:(NSError **)error;

@end
