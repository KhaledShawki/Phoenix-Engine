#pragma once
// 
// #include <iostream>
// #include <string>
// 
// namespace Phx {
// 
// 	class AudioSource {
// 
// 	public:
// 		~AudioSource();
// 
// 		bool IsLoaded() const { return m_Loaded; }
// 
// 		void SetPosition(float x, float y, float z);
// 		void SetGain(float gain);
// 		void SetPitch(float pitch);
// 		void SetLoop(bool loop);
// 
// 		std::pair<uint32_t, uint32_t> GetLengthMinutesAndSeconds() const;
// 
// 		static AudioSource LoadFromFile(const std::string& file, bool spatial = false);
// 	private:
// 		AudioSource() = default;
// 		AudioSource(uint32_t handle, bool loaded, float length);
// 
// 		uint32_t m_BufferHandle = 0;
// 		uint32_t m_SourceHandle = 0;
// 
// 		bool m_Loaded = false;
// 		bool m_Spatial = false;
// 
// 		float m_TotalDuration = 0; // in seconds
// 
// 		float m_Position[3] = { 0.0f,0.0f,0.0f };
// 		float m_Gain = 1.0f;
// 		float m_Pitch = 1.0f;
// 		bool m_Loop = false;
// 
// 		friend class Audio;
// 	};
// 
// 	class Audio {
// 
// 	public:
// 		static void Init();
// 
// 		static AudioSource LoadAudio(const std::string& filename);
// 		static void Unload(AudioSource& audio);
// 		static void Play(AudioSource& audio);
// 
// 	private:
// 		static AudioSource LoadAudioOgg(const std::string& filename);
// 		static AudioSource LoadAudioMP3(const std::string& filename);
// 	};
// }