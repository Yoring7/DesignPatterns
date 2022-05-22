#include<iostream>
#include<string>
using namespace std;

// 适配器模式

// 媒体播放器接口
class MediaPlayer
{
public:
    virtual void Play(string audioType, string fileName) = 0;
};

// 高级的媒体播放器接口
class AdvancedMediaPlayer
{
public:
    virtual void PlayVlc(string fileName) = 0;
    virtual void PlayMp4(string fileName) = 0;
};

// vlc播放器
class VlcPlayer : public AdvancedMediaPlayer
{
public:
    void PlayVlc(string fileName) override
    {
        std::cout << "Playing vlc file. Name: " << fileName << std::endl;
    }
    void PlayMp4(string fileName) override
    {
        // do nothing
    }
};

// mp4播放器
class Mp4Player : public AdvancedMediaPlayer
{
public:
    void PlayVlc(string fileName) override
    {
        // do nothing
    }
    void PlayMp4(string fileName) override
    {
        std::cout << "Playing mp4 file. Name: " << fileName << std::endl;
    }
};

// 播放器适配器（继承播放器）
class MediaAdapter : public MediaPlayer
{
private:
    // 实例化高级播放器，为了调用其中的方法
    // 注意这里体现了针对接口编程
    // 将算法和对象分离
    AdvancedMediaPlayer *player;
public:
    // 构造函数
    MediaAdapter(string audioType)
    {
        if (audioType == "vlc")
        {
            player = new VlcPlayer();
        }
        else if (audioType == "mp4")
        {
            player = new Mp4Player();
        }
    }
    // 重写播放方法
    void Play(string audioType, string fileName) override
    {
        if (audioType == "vlc")
        {
            player->PlayVlc(fileName);
        }
        else if (audioType == "mp4")
        {
            player->PlayMp4(fileName);
        }
    }
};

// 
class AudioPlayer : public MediaPlayer
{
private:
    // 适配器（本质上就是调用了新播放器的功能）
    MediaAdapter *adapter;
public:
    AudioPlayer(string audioType)
    {
        if (audioType == "vlc" || audioType == "mp4")
        {
            adapter = new MediaAdapter(audioType);
        }
    }
    void Play(string audioType, string fileName) override
    {
        if (audioType == "mp3")
        {
            std::cout << "Playing mp3 file. Name: " << fileName << std::endl;
        }
        else if (audioType == "vlc" || audioType == "mp4")
        {
            adapter->Play(audioType, fileName);
        }
    }
};

int main()
{
    AudioPlayer *player = new AudioPlayer("mp4");
    player->Play("mp4", "test.mp4");
    player->Play("vlc", "test.vlc");
    player->Play("mp3", "test.mp3");
    delete player;
    return 0;
}



