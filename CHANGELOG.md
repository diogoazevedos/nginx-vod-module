# Change Log

All notable changes to this project will be documented in this file.

## [1.1.0](https://github.com/diogoazevedos/nginx-vod-module/compare/v1.0.0...v1.1.0) (2025-05-16)

### Features

- Update minimum HLS version ([#26](https://github.com/diogoazevedos/nginx-vod-module/pull/26))
- Add HLS independent segments tag ([#25](https://github.com/diogoazevedos/nginx-vod-module/pull/25))

### Bug Fixes

- Ensure that DASH request version is correct ([#28](https://github.com/diogoazevedos/nginx-vod-module/pull/28))

## [1.0.0](https://github.com/diogoazevedos/nginx-vod-module/compare/26f06877b0f2a2336e59cda93a3de18d7b23a3e2...v1.0.0) (2025-05-06)

### ⚠ BREAKING CHANGES

- Drop support for HDS and MSS ([#13](https://github.com/diogoazevedos/nginx-vod-module/pull/13))
- Improve compliance with DASH specification ([#11](https://github.com/diogoazevedos/nginx-vod-module/pull/11))
- Use last audio track assuming higher bitrate ([#9](https://github.com/diogoazevedos/nginx-vod-module/pull/9))

### Features

- Add quick development setup ([#20](https://github.com/diogoazevedos/nginx-vod-module/pull/20))
- Support sequence ID in the representation ID ([#17](https://github.com/diogoazevedos/nginx-vod-module/pull/17))
- Add HLS characteristics support ([#6](https://github.com/diogoazevedos/nginx-vod-module/pull/6))
- Add DASH role scheme support ([#5](https://github.com/diogoazevedos/nginx-vod-module/pull/5))
- Update CI dependencies ([#4](https://github.com/diogoazevedos/nginx-vod-module/pull/4))

### Bug Fixes

- Fix DASH representation ID for single sequence ([#23](https://github.com/diogoazevedos/nginx-vod-module/pull/23))
- Ensure that clock_gettime check works ([#22](https://github.com/diogoazevedos/nginx-vod-module/pull/22))
- Ensure that lang and label are not empty ([#12](https://github.com/diogoazevedos/nginx-vod-module/pull/12))
- Ensure that track grouping is correct ([#10](https://github.com/diogoazevedos/nginx-vod-module/pull/10))
- Ensure that each audio group has a default ([#8](https://github.com/diogoazevedos/nginx-vod-module/pull/8))
- Ensure that sequence autoselect is enabled by default ([#7](https://github.com/diogoazevedos/nginx-vod-module/pull/7))
- Ensure that media info inherits the sequence tags ([#1](https://github.com/diogoazevedos/nginx-vod-module/pull/1))

> For previous versions please check at
[`kaltura/nginx-vod-module/CHANGELOG.md`](https://github.com/kaltura/nginx-vod-module/blob/26f06877b0f2a2336e59cda93a3de18d7b23a3e2/CHANGELOG.md).
