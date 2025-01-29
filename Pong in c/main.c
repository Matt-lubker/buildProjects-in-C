#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define PADDLE_WIDTH 10
#define PADDLE_HEIGHT 100
#define BALL_SIZE 10
#define PADDLE_SPEED 10
#define BALL_SPEED 5

typedef struct {
    int x, y, w, h;
} Paddle;

typedef struct {
    int x, y, w, h, dx, dy;
} Ball;

void move_paddle(Paddle *paddle, int direction) {
    paddle->y += direction * PADDLE_SPEED;
    if (paddle->y < 0) paddle->y = 0;
    if (paddle->y > SCREEN_HEIGHT - PADDLE_HEIGHT) paddle->y = SCREEN_HEIGHT - PADDLE_HEIGHT;
}

void move_ball(Ball *ball, Paddle *p1, Paddle *p2) {
    ball->x += ball->dx;
    ball->y += ball->dy;

    
    if (ball->y <= 0 || ball->y >= SCREEN_HEIGHT - BALL_SIZE) {
        ball->dy = -ball->dy;
    }


    if ((ball->x <= p1->x + PADDLE_WIDTH && ball->y + BALL_SIZE >= p1->y && ball->y <= p1->y + PADDLE_HEIGHT) ||
        (ball->x + BALL_SIZE >= p2->x && ball->y + BALL_SIZE >= p2->y && ball->y <= p2->y + PADDLE_HEIGHT)) {
        ball->dx = -ball->dx;
    }

  
    if (ball->x < 0 || ball->x > SCREEN_WIDTH) {
        ball->x = SCREEN_WIDTH / 2;
        ball->y = SCREEN_HEIGHT / 2;
        ball->dx = (ball->dx > 0) ? -BALL_SPEED : BALL_SPEED;
        ball->dy = BALL_SPEED;
    }
}

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Paddle p1 = {20, SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2, PADDLE_WIDTH, PADDLE_HEIGHT};
    Paddle p2 = {SCREEN_WIDTH - 30, SCREEN_HEIGHT / 2 - PADDLE_HEIGHT / 2, PADDLE_WIDTH, PADDLE_HEIGHT};
    Ball ball = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, BALL_SIZE, BALL_SIZE, BALL_SPEED, BALL_SPEED};

    int running = 1;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        
        const Uint8 *keystate = SDL_GetKeyboardState(NULL);
        if (keystate[SDL_SCANCODE_W]) move_paddle(&p1, -1);
        if (keystate[SDL_SCANCODE_S]) move_paddle(&p1, 1);

        
        if (keystate[SDL_SCANCODE_UP]) move_paddle(&p2, -1);
        if (keystate[SDL_SCANCODE_DOWN]) move_paddle(&p2, 1);

        move_ball(&ball, &p1, &p2);

        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_Rect p1_rect = {p1.x, p1.y, p1.w, p1.h};
        SDL_Rect p2_rect = {p2.x, p2.y, p2.w, p2.h};
        SDL_Rect ball_rect = {ball.x, ball.y, ball.w, ball.h};
        SDL_RenderFillRect(renderer, &p1_rect);
        SDL_RenderFillRect(renderer, &p2_rect);
        SDL_RenderFillRect(renderer, &ball_rect);

        SDL_RenderPresent(renderer);
        SDL_Delay(16); 
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
