from moviepy.editor import *
from gtts import gTTS


def text_to_speech(text):
    tts = gTTS(text)
    audio_path = "speech1.mp3"
    tts.save(audio_path)
    return AudioFileClip(audio_path)


def generate_video_from_text(text):
    # Convert text to speech using a TTS library

    speech = text_to_speech(text)  # Replace with your TTS implementation

    # Create a blank video clip with desired settings
    duration = len(speech)  # Duration of the speech audio
    video_clip = ColorClip((1280, 720), duration=duration, col="white")

    # Set the audio for the video clip
    video_clip = video_clip.set_audio(speech)

    # Render the video to a file
    video_clip.write_videofile(
        "output.mp4", codec="libx264", audio_codec="aac")


# Example usage
text = "Hello, World"
generate_video_from_text(text)
