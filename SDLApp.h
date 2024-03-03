#ifndef SDLAPP_H
#define SDLAPP_H

#include <QObject>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string>

class SDLApp : public QObject {
    Q_OBJECT
public:
    explicit SDLApp(QObject *parent = nullptr);
    ~SDLApp();

    bool init();
    void processEvents();
    void toggleLine();
    void submitText(const std::string &text); // Method to receive and handle submitted text
    bool shouldQuit() const;
    void cleanUp();

signals:
    void textEntered(const QString& text); // Signal to notify when text is entered
    void quitApplication();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* imageTexture; // Member variable to hold the image texture
    bool drawLineFlag;
    bool quit;
    std::string buttonText; // Existing member variable

    // UI dimensions for buttons
    static constexpr int BUTTON_WIDTH = 200;
    static constexpr int BUTTON_HEIGHT = 50;
    int buttonX = 220;
    int buttonY = 200;

    bool textInputMode;
    std::string textInputBuffer;

    TTF_Font* font;
    SDL_Color textColor;

    std::string submittedText; // Store the text submitted from the Qt window

    // Rendering methods
    void render();
    void renderText(const std::string& message, int x, int y, int fontSize);
    void renderButton(SDL_Renderer* renderer, const char* text, int x, int y);
    bool isMouseInsideButton(int mouseX, int mouseY, int buttonX, int buttonY, int buttonWidth, int buttonHeight);
    void handleButtonClick(SDL_Event& event);
    void handleTextInput(SDL_Event& event);
};

#endif // SDLAPP_H
