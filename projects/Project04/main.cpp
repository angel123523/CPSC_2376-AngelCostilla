#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <iostream>
#include "minesweeper.h"
#include "Engine.h"


void drawHoveredCell(Engine& engine, int row, int col) {
    if (row >= 0 && col >= 0) {
        SDL_Color hoverColor = { 255, 255, 0, 100 }; 
        engine.drawRectangle(col * 100 + 50, row * 100 + 50, 100, 100, hoverColor);
    }
}


void drawBoard(Engine& engine, const Minesweeper& game, int hoverRow, int hoverCol) {
    SDL_Color coveredColor = { 0, 0, 255, 255 }; 
    SDL_Color revealedColor = { 0, 255, 0, 255 }; 
    SDL_Color mineColor = { 255, 0, 0, 255 }; 

    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 5; ++col) {
            if (game.isRevealed(row, col)) {
                if (game.isMine(row, col)) {
                    engine.drawRectangle(col * 100 + 50, row * 100 + 50, 100, 100, mineColor);
                }
                else {
                    engine.drawRectangle(col * 100 + 50, row * 100 + 50, 100, 100, revealedColor);
                }
            }
            else {
                engine.drawRectangle(col * 100 + 50, row * 100 + 50, 100, 100, coveredColor);
            }
        }
    }

  
    drawHoveredCell(engine, hoverRow, hoverCol);
}

int main() {
    Engine engine("Minesweeper SDL", 500, 500);  
    bool quit = false;

    while (!quit) {
        Minesweeper game(5, 5, 5); 
        bool running = true;
        int hoverRow = -1, hoverCol = -1;

        while (running) {
            SDL_Event e;
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_QUIT) {
                    quit = true;
                    running = false;
                }
                else if (e.type == SDL_MOUSEBUTTONDOWN) {
                    int x, y;
                    SDL_GetMouseState(&x, &y);
                    int row = y / 100;
                    int col = x / 100;
                    if (game.status() == GameStatus::ONGOING) {
                        game.play(row, col);
                    }
                }
                else if (e.type == SDL_MOUSEMOTION) {
                    hoverCol = e.motion.x / 100;
                    hoverRow = e.motion.y / 100;
                }
                else if (e.type == SDL_KEYDOWN) {
                    if (e.key.keysym.sym == SDLK_ESCAPE) {
                        quit = true;
                        running = false;
                    }
                    else if (e.key.keysym.sym == SDLK_SPACE) {
                        if (game.status() != GameStatus::ONGOING)
                            running = false;
                    }
                }
            }

            engine.clear();  

            
            drawBoard(engine, game, hoverRow, hoverCol);

           
            if (game.status() != GameStatus::ONGOING) {
                SDL_Color msgColor = { 255, 255, 255, 255 };
                std::string msg = (game.status() == GameStatus::PLAYER_1_WINS) ? "Player 1 Wins!" :
                    (game.status() == GameStatus::PLAYER_2_WINS) ? "Player 2 Wins!" : "Draw";
                engine.drawText(msg, 250, 20, msgColor);  // 
            }

            engine.flip(); 
            SDL_Delay(16);  
        }
    }

    return 0;
}