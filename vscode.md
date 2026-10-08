{
// ==========================================
// Editor
// ==========================================
"editor.fontFamily": "'Cascadia Code', Consolas, monospace",
"editor.fontSize": 16,
"editor.lineHeight": 28,
"editor.letterSpacing": 0.4,
"editor.fontLigatures": true,
"workbench.tree.enableStickyScroll": false,
"workbench.tree.renderIndentGuides": "none",
"workbench.tree.indent": 16,
"explorer.compactFolders": false,

// ==========================================
// Breadcrumb
// ==========================================
"breadcrumbs.enabled": false,

"editor.insertSpaces": true,
"editor.tabSize": 2,
"editor.detectIndentation": false,
"editor.formatOnSave": true,
"editor.formatOnPaste": true,
"editor.formatOnType": true,

"editor.codeActionsOnSave": {
"source.fixAll.eslint": "explicit",
"source.organizeImports": "explicit"
},

"editor.wordWrap": "on",
"editor.wordWrapColumn": 100,
"editor.minimap.enabled": false,
"editor.cursorStyle": "line",
"editor.cursorBlinking": "expand",
"editor.cursorSmoothCaretAnimation": "on",
"editor.cursorWidth": 2,
"editor.linkedEditing": true,
"editor.smoothScrolling": true,
"editor.renderWhitespace": "selection",
"editor.renderLineHighlight": "all",
"editor.inlineSuggest.enabled": true,

"editor.quickSuggestions": {
"other": true,
"comments": false,
"strings": true
},

"editor.tabCompletion": "on",
"editor.acceptSuggestionOnEnter": "on",
"editor.suggestSelection": "first",
"editor.parameterHints.enabled": true,
"editor.bracketPairColorization.enabled": true,
"editor.guides.bracketPairs": "active",
"editor.guides.bracketPairsHorizontal": "active",
"editor.guides.indentation": true,
"editor.guides.highlightActiveIndentation": true,
"editor.inlayHints.enabled": "on",
"editor.copyWithSyntaxHighlighting": true,
"editor.snippetSuggestions": "top",
"editor.stickyScroll.enabled": false,
"editor.mouseWheelZoom": true,

// ==========================================
// Prettier
// ==========================================
"prettier.singleQuote": true,
"prettier.semi": true,
"prettier.trailingComma": "es5",
"prettier.tabWidth": 2,
"prettier.useTabs": false,

// ==========================================
// Files
// ==========================================
"files.autoSave": "onFocusChange",
"files.trimTrailingWhitespace": true,
"files.insertFinalNewline": true,
"files.trimFinalNewlines": true,

"files.exclude": {
"\*\*/.DS_Store": true
},

// ==========================================
// Explorer
// ==========================================
"explorer.confirmDelete": false,
"explorer.confirmDragAndDrop": false,
"explorer.sortOrder": "type",
"explorer.openEditors.visible": 1,
"explorer.fileNesting.enabled": true,

"explorer.fileNesting.patterns": {
"package.json": "package-lock.json,yarn.lock,pnpm-lock.yaml",
"tsconfig.json": "tsconfig._.json",
".env": ".env._"
},

// ==========================================
// Search
// ==========================================
"search.exclude": {
"**/node_modules": true,
"**/dist": true,
"**/build": true,
"**/.next": true,
"\*\*/coverage": true
},

"search.followSymlinks": false,

// ==========================================
// Terminal
// ==========================================
"terminal.integrated.defaultProfile.windows": "PowerShell",
"terminal.integrated.defaultLocation": "editor",
"terminal.integrated.fontFamily": "JetBrainsMono Nerd Font",
"terminal.integrated.fontSize": 15,
"terminal.integrated.cursorStyle": "line",
"terminal.integrated.cursorBlinking": true,
"terminal.integrated.scrollback": 10000,
"terminal.integrated.gpuAcceleration": "on",
"terminal.integrated.smoothScrolling": true,
"terminal.integrated.tabs.enabled": true,
"terminal.integrated.tabs.location": "right",
"terminal.integrated.localEchoStyle": "inverted",

// ==========================================
// Git
// ==========================================
"git.enableSmartCommit": true,
"git.autofetch": true,
"git.confirmSync": false,
"git.decorations.enabled": true,
"git.openRepositoryInParentFolders": "always",

// ==========================================
// Emmet
// ==========================================
"emmet.includeLanguages": {
"javascript": "javascriptreact",
"typescript": "typescriptreact"
},

"emmet.triggerExpansionOnTab": true,
"emmet.showExpandedAbbreviation": "always",

// ==========================================
// Workbench
// ==========================================
"workbench.productIconTheme": "el-vsc-v1-icons",
"workbench.startupEditor": "none",
"workbench.editor.showTabs": "single",
"workbench.activityBar.location": "bottom",
"workbench.activityBar.compact": true,
"workbench.statusBar.visible": false,
"workbench.layoutControl.enabled": false,
"workbench.editor.wrapTabs": true,

"workbench.colorTheme": "Catppuccin Mocha",
"workbench.iconTheme": "material-icon-theme",

// ==========================================
// Window
// ==========================================
"window.commandCenter": false,
"window.zoomLevel": 1,
"window.menuBarVisibility": "compact",
"window.openFoldersInNewWindow": "on",

// ==========================================
// Error Lens
// ==========================================
"errorLens.enabled": true,
"errorLens.messageEnabled": true,

// ==========================================
// GitHub Copilot
// ==========================================
"github.copilot.enable": {
"\*": false,
"plaintext": false,
"markdown": false,
"scminput": false
},

// ==========================================
// Other
// ==========================================
"chat.titleBar.openInAgentsWindow.enabled": false,
"workbench.browser.sendElementsToChat.attachImages": false,
"diffEditor.hideUnchangedRegions.enabled": true,
"debug.onTaskErrors": "debugAnyway",

"js/ts.format.insertSpaceAfterOpeningAndBeforeClosingJsxExpressionBraces": true,

// ==========================================
// Language Formatters
// ==========================================
"[typescriptreact]": {
"editor.defaultFormatter": "esbenp.prettier-vscode"
},

"[javascriptreact]": {
"editor.defaultFormatter": "esbenp.prettier-vscode"
},

"[html]": {
"editor.defaultFormatter": "esbenp.prettier-vscode"
},

"[typescript]": {
"editor.defaultFormatter": "esbenp.prettier-vscode"
},

"[css]": {
"editor.defaultFormatter": "esbenp.prettier-vscode"
},

"[javascript]": {
"editor.defaultFormatter": "esbenp.prettier-vscode"
},

"[json]": {
"editor.defaultFormatter": "esbenp.prettier-vscode"
},

// ==========================================
// GitLens
// ==========================================
"gitlens.views.scm.grouped.views": {
"commits": true,
"branches": true,
"remotes": true,
"stashes": true,
"tags": true,
"worktrees": true,
"contributors": true,
"fileHistory": false,
"repositories": true,
"searchAndCompare": false,
"launchpad": true
},

"chat.viewSessions.orientation": "stacked",

// ==========================================
// Material Icon Theme - MERN Files
// ==========================================
"material-icon-theme.files.associations": {
// JavaScript / TypeScript
"_.js": "javascript",
"_.jsx": "react",
"_.mjs": "javascript",
"_.cjs": "javascript",
"_.ts": "typescript",
"_.tsx": "react_ts",

    // MERN Backend
    "*.controller.js": "controller",
    "*.controller.ts": "controller",

    "*.model.js": "database",
    "*.model.ts": "database",

    "*.schema.js": "database",
    "*.schema.ts": "database",

    "*.service.js": "services",
    "*.service.ts": "services",

    "*.routes.js": "routes",
    "*.routes.ts": "routes",

    "*.route.js": "routes",
    "*.route.ts": "routes",

    "*.middleware.js": "middleware",
    "*.middleware.ts": "middleware",

    "*.config.js": "config",
    "*.config.ts": "config",

    "*.utils.js": "utils",
    "*.utils.ts": "utils",

    "*.helper.js": "helper",
    "*.helper.ts": "helper",

    "*.constant.js": "constant",
    "*.constants.js": "constant",

    "*.validation.js": "validation",
    "*.validation.ts": "validation",

    "*.validator.js": "validation",
    "*.validator.ts": "validation",

    "*.repository.js": "database",
    "*.repository.ts": "database",

    "*.seed.js": "database",
    "*.seed.ts": "database",

    // Testing
    "*.test.js": "test",
    "*.test.ts": "test",
    "*.test.jsx": "test",
    "*.test.tsx": "test",

    "*.spec.js": "test",
    "*.spec.ts": "test",
    "*.spec.jsx": "test",
    "*.spec.tsx": "test",

    // React
    "*.component.jsx": "react",
    "*.component.tsx": "react_ts",

    "*.page.jsx": "react",
    "*.page.tsx": "react_ts",

    "*.hook.js": "hook",
    "*.hook.jsx": "hook",
    "*.hook.ts": "hook",
    "*.hook.tsx": "hook",

    "*.context.js": "context",
    "*.context.jsx": "context",
    "*.context.ts": "context",
    "*.context.tsx": "context",

    "*.slice.js": "redux-store",
    "*.slice.ts": "redux-store",

    "*.store.js": "redux-store",
    "*.store.ts": "redux-store",

    "*.reducer.js": "redux-reducer",
    "*.reducer.ts": "redux-reducer",

    "*.action.js": "redux-action",
    "*.action.ts": "redux-action",

    // Package / Config
    "package.json": "npm",
    "package-lock.json": "npm",
    "yarn.lock": "yarn",
    "pnpm-lock.yaml": "pnpm",

    "vite.config.js": "vite",
    "vite.config.ts": "vite",

    "next.config.js": "next",
    "next.config.mjs": "next",

    "tailwind.config.js": "tailwind",
    "tailwind.config.ts": "tailwind",

    "webpack.config.js": "webpack",
    "babel.config.js": "babel",

    // Environment
    ".env": "tune",
    ".env.local": "tune",
    ".env.development": "tune",
    ".env.production": "tune",
    ".env.test": "tune",
    "*.env": "tune",

    // Web
    "*.html": "html",
    "*.css": "css",
    "*.scss": "sass",
    "*.sass": "sass",
    "*.less": "less",
    "*.json": "json",
    "*.md": "markdown",
    "*.txt": "file",

    // Images
    "*.png": "image",
    "*.jpg": "image",
    "*.jpeg": "image",
    "*.gif": "image",
    "*.webp": "image",
    "*.svg": "svg",
    "*.ico": "favicon",

    // Docker
    "Dockerfile": "docker",
    "docker-compose.yml": "docker",
    "docker-compose.yaml": "docker",

    // Git
    ".gitignore": "git",
    ".gitattributes": "git",
    ".gitmodules": "git",

    // Common Node / MERN files
    "server.js": "nodejs",
    "app.js": "nodejs",
    "index.js": "nodejs",
    "server.ts": "nodejs",
    "app.ts": "nodejs",
    "index.ts": "nodejs",

    "db.js": "database",
    "database.js": "database",
    "connection.js": "database",
    "config.js": "config"

},

// ==========================================
// Material Icon Theme - MERN Folders
// ==========================================
"material-icon-theme.folders.associations": {
// Frontend
"src": "src",
"components": "components",
"component": "components",
"pages": "views",
"views": "views",
"layouts": "layout",
"layout": "layout",

    // React
    "hooks": "hook",
    "contexts": "context",
    "context": "context",
    "store": "redux-store",
    "redux": "redux-store",
    "features": "components",

    // Backend
    "controllers": "controller",
    "controller": "controller",

    "models": "database",
    "model": "database",

    "schemas": "database",
    "schema": "database",

    "routes": "routes",
    "route": "routes",

    "middleware": "middleware",
    "middlewares": "middleware",

    "services": "services",
    "service": "services",

    "repositories": "database",
    "repository": "database",

    "utils": "utils",
    "utilities": "utils",

    "helpers": "helper",
    "helper": "helper",

    "config": "config",
    "configs": "config",

    "constants": "constant",
    "constant": "constant",

    "validators": "validation",
    "validation": "validation",
    "validations": "validation",

    // Assets
    "assets": "assets",
    "images": "images",
    "icons": "icons",
    "fonts": "font",
    "public": "public",
    "static": "public",
    "uploads": "upload",

    // Testing
    "test": "test",
    "tests": "test",
    "__tests__": "test",

    // Build / Dependencies
    "node_modules": "node_modules",
    "dist": "dist",
    "build": "dist",
    "coverage": "coverage",

    // Documentation
    "docs": "docs",
    "documentation": "docs",

    // GitHub
    ".github": "github",
    "workflows": "github",

    // Docker
    "docker": "docker",
    "dockerfiles": "docker"

}
}
